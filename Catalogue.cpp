/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 19/11/2018
    copyright            : (C) 2018 par Thiago Verny & Taoyang Liu
    e-mail               : thiago.verny@insa-lyon.fr
                           taoyang.liu@insa-lyon.fr
*************************************************************************/

//---- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <cstring>
#include <typeinfo>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes
#define TAILLE 100
#define SEPARATEUR ','
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::Afficher() const
// Algorithme :
//     Fait appel à la méthode Trajet::Afficher() pour chaque objet
{
    for(int i=0; i<leCatalogue->GetNombreDeTrajets(); i++)
    {
	    leCatalogue->GetTrajet(i)->Afficher();
    }
}

void Catalogue::Ajouter (const Trajet* t)
// Algorithme :
//     Fait appel à la méthode VecteurTrajet::Ajouter()
{
    leCatalogue->Ajouter(t);	
}

void Catalogue::RechercherSimple (const char* villeDepart, const char* villeDestination) const
// Algorithme :
//     Pour chacun des Trajets du Catalogue, compare les villes de départ
//     et d'arrivée avec celles passées en paramètre, et affiche le Trajet 
//     en cas d'égalité
{
    bool trouve = false;
    cout << "======= Recherche Simple =======" << endl;
    for (int i=0; i<leCatalogue->GetNombreDeTrajets(); i++)
    {
        if (strcmp(villeDepart, leCatalogue->GetTrajet(i)->GetDepart()) == 0
	        && strcmp(villeDestination, leCatalogue->GetTrajet(i)->GetArrivee()) == 0 )
        {
            leCatalogue->GetTrajet(i)->Afficher();
            trouve = true;
	    }
    }
    if(!trouve)
    {
        cout << "Aucun trajet trouvé de " << *villeDepart << " à " << *villeDestination << endl;
    }
    cout << endl;
}

int Catalogue::Rechercher (const char* villeDepart, const char* villeDestination) const
// Algorithme :
//     Pour chaque trajet, si la ville de départ correspond, alors
//     on trouve toutes les combinaisons de trajets pouvant mener à
//     la ville de destination
{
    if (strcmp(villeDepart, villeDestination) != 0)
    {
        char* villesVisitees[TAILLE];
        int nbVillesVisitees = 0;

        bool pasDeTrajets = true;
        bool dejaVisite = false;

        for (int i=0; i<leCatalogue->GetNombreDeTrajets(); i++)
        {
            if (strcmp(villeDepart, leCatalogue->GetTrajet(i)->GetDepart()) == 0)
            // les trajets qui partent de villeDepart
            {
                dejaVisite = false;
                for (int j=0; i<nbVillesVisitees; i++)
                {
                    if (strcmp(leCatalogue->GetTrajet(i)->GetArrivee(), villesVisitees[j]) == 0)
                    {
                        dejaVisite = true;
                    }
                }
                if (!dejaVisite)
                {
                    pasDeTrajets = false;
                    leCatalogue->GetTrajet(i)->Afficher();
                    villesVisitees[nbVillesVisitees++] = leCatalogue->GetTrajet(i)->GetArrivee();
                    char* nouveauDepart = leCatalogue->GetTrajet(i)->GetArrivee();
                    this->Rechercher(nouveauDepart, villeDestination);
                }
                
            }
        }
        if (pasDeTrajets)
        {
            return 1;
        }
    }
    else
    {
        return -1;
    }
    return 0;
}

void Catalogue::Lire (const string nomDuFichier)
// Algorithme :
//     
{
  ifstream fichier (nomDuFichier);
  if ( ! fichier)
  {
    cerr << "Erreur d'ouverture du fichier <" << nomDuFichier << ">" <<endl;
  }
  char ligneCourante[TAILLE];
  char ligneCouranteCopie[TAILLE];
  char * pointeurCourant;
  fichier.get(ligneCourante,2);// Nombre maximal de trajets dans le catalogue stocké : 99
  fichier.get();	       // Suppression du retour à la ligne.
  int nbTrajets = stoi(ligneCourante); 
  for(int i(0) ; i<nbTrajets ; i++)
  {
	fichier.getline(ligneCourante,TAILLE); 		  //Récupère l'intégralité de la ligne.
	strcpy(ligneCouranteCopie,ligneCourante); 	  // Ligne utilisée pour le traitement des informations (strtok tronque)
	pointeurCourant = strtok(ligneCouranteCopie,","); // Ote le numéro de ligne (inutilisé dans cette implémentation de Lire)
	pointeurCourant = strtok(NULL,","); 		  //Récupère le type de trajet (TS/TC)
	if(!strcmp(pointeurCourant, "TS"))
	{
		TrajetSimple * trajetS = CreationTrajetSimple(ligneCourante);
		this->Ajouter(trajetS);
		delete trajetS;
	}
	else if(!strcmp(pointeurCourant,"TC"))
	{
		pointeurCourant = strtok(NULL,","); 	  // Recupère le nombre de trajets composants le trajet composé
		TrajetCompose * trajetCompose = new TrajetCompose(); 
		int nbTrajetsComposants = stoi(pointeurCourant);
		for(int j (0); j <nbTrajetsComposants; j++)
		{
			
			fichier.getline(ligneCourante,TAILLE);
			TrajetSimple * trajetSComposant = CreationTrajetSimple(ligneCourante);
			trajetCompose->AjouterSousTrajet(trajetSComposant);
			delete trajetSComposant;
			
		}
		this->Ajouter(trajetCompose);
		delete trajetCompose;
	} 
	fichier.getline(ligneCourante,TAILLE);
}
}

void Catalogue::Lire (const string nomDuFichier, const string & typeDeTrajet)
{
  ifstream fichier (nomDuFichier);
  if ( ! fichier)
  {
    cerr << "Erreur d'ouverture du fichier <" << nomDuFichier << ">" <<endl;
  }
  char ligneCourante[TAILLE];
  char ligneCouranteCopie[TAILLE];
  char * pointeurCourant;
  fichier.get(ligneCourante,2);// Nombre maximal de trajets dans le catalogue stocké : 99
  fichier.get();	       // Suppression du retour à la ligne.
  int nbTrajets = stoi(ligneCourante); 
  for(int i(0) ; i<nbTrajets ; i++)
  {
	fichier.getline(ligneCourante,TAILLE); 		  //Récupère l'intégralité de la ligne.
	strcpy(ligneCouranteCopie,ligneCourante); 	  // Ligne utilisée pour le traitement des informations (strtok tronque)
	pointeurCourant = strtok(ligneCouranteCopie,","); // Ote le numéro de ligne (inutilisé dans cette implémentation de Lire)
	pointeurCourant = strtok(NULL,","); 		  //Récupère le type de trajet (TS/TC)
	if(!strcmp(pointeurCourant,"TS") && !strcmp(pointeurCourant,typeDeTrajet.c_str()))
	{
		TrajetSimple * trajetS = CreationTrajetSimple(ligneCourante);
		this->Ajouter(trajetS);
		delete trajetS;
	}
	else if(!strcmp(pointeurCourant,"TC") && !strcmp(pointeurCourant,typeDeTrajet.c_str()))
	{
		pointeurCourant = strtok(NULL,","); 	  // Recupère le nombre de trajets composants le trajet composé
		TrajetCompose * trajetCompose = new TrajetCompose(); 
		int nbTrajetsComposants = stoi(pointeurCourant);
		for(int j (0); j <nbTrajetsComposants; j++)
		{
			
			fichier.getline(ligneCourante,TAILLE);
			TrajetSimple * trajetSComposant = CreationTrajetSimple(ligneCourante);
			trajetCompose->AjouterSousTrajet(trajetSComposant);
			delete trajetSComposant;
			
		}
		this->Ajouter(trajetCompose);
		delete trajetCompose;
	} 
	fichier.getline(ligneCourante,TAILLE);
}
}

void Catalogue::Lire (const string nomDuFichier, const string & villeDepart, const string & villeArrivee)
// faire un test, si un des deux = "" alors que l'autre sera considéré, sinon les deux.
{
  ifstream fichier (nomDuFichier);
  if ( ! fichier)
  {
    cerr << "Erreur d'ouverture du fichier <" << nomDuFichier << ">" <<endl;
  }
  char ligneCourante[TAILLE];
  char ligneCouranteCopie[TAILLE];
  char * pointeurCourant;
  fichier.get(ligneCourante,2);// Nombre maximal de trajets dans le catalogue stocké : 99
  fichier.get();	       // Suppression du retour à la ligne.
  int nbTrajets = stoi(ligneCourante); 
  for(int i(0) ; i<nbTrajets ; i++)
  {
	fichier.getline(ligneCourante,TAILLE); 		  //Récupère l'intégralité de la ligne.
	strcpy(ligneCouranteCopie,ligneCourante); 	  // Ligne utilisée pour le traitement des informations (strtok tronque)
	pointeurCourant = strtok(ligneCouranteCopie,","); // Ote le numéro de ligne (inutilisé dans cette implémentation de Lire)
	pointeurCourant = strtok(NULL,","); 		  //Récupère le type de trajet (TS/TC)
	if(!strcmp(pointeurCourant,"TS"))
	{
		TrajetSimple * trajetS = CreationTrajetSimple(ligneCourante);
		if(VerificationsInfoTrajet(*trajetS,villeDepart,villeArrivee))
		{
				this->Ajouter(trajetS);
		}
		delete trajetS;
	}
	else if(!strcmp(pointeurCourant,"TC"))
	{
		pointeurCourant = strtok(NULL,","); 	  // Recupère le nombre de trajets composants le trajet composé
		TrajetCompose * trajetCompose = new TrajetCompose(); 
		int nbTrajetsComposants = stoi(pointeurCourant);
		for(int j (0); j <nbTrajetsComposants; j++)
		{
			
			fichier.getline(ligneCourante,TAILLE);
			TrajetSimple * trajetSComposant = CreationTrajetSimple(ligneCourante);
			trajetCompose->AjouterSousTrajet(trajetSComposant);
			delete trajetSComposant;
			
		}
		if(VerificationsInfoTrajet(*trajetCompose,villeDepart,villeArrivee)){
			this->Ajouter(trajetCompose);
		}
		delete trajetCompose;
	} 
	fichier.getline(ligneCourante,TAILLE);
  }
}

void Catalogue::Lire (const string nomDuFichier, const int n,const int m)
// Algorithme :
//
{
  ifstream fichier (nomDuFichier);
  if ( ! fichier)
  {
    cerr << "Erreur d'ouverture du fichier <" << nomDuFichier << ">" <<endl;
  }
  char ligneCourante[TAILLE];
  char ligneCouranteCopie[TAILLE];
  char * pointeurCourant;
  int indiceDeLigne;
  fichier.get(ligneCourante,2);// Nombre maximal de trajets dans le catalogue stocké : 99
  fichier.get();	       // Suppression du retour à la ligne.
  int nbTrajets = stoi(ligneCourante); 
  for(int i(0) ; i<nbTrajets ; i++)
  {
	fichier.getline(ligneCourante,TAILLE); 		  //Récupère l'intégralité de la ligne.
	strcpy(ligneCouranteCopie,ligneCourante); 	  // Ligne utilisée pour le traitement des informations (strtok tronque)
	pointeurCourant = strtok(ligneCouranteCopie,",");
	indiceDeLigne = stoi(pointeurCourant);
	pointeurCourant = strtok(NULL,","); 		  //Récupère le type de trajet (TS/TC)
	if(!strcmp(pointeurCourant,"TS"))
	{
		if(indiceDeLigne >= n && indiceDeLigne <= m)
		{
			TrajetSimple * trajetS = CreationTrajetSimple(ligneCourante);
			this->Ajouter(trajetS);
			delete trajetS;
		}
	}
	else if(!strcmp(pointeurCourant,"TC"))
	{
		pointeurCourant = strtok(NULL,","); 	  // Recupère le nombre de trajets composants le trajet composé
		int nbTrajetsComposants = stoi(pointeurCourant);
		if(indiceDeLigne < n || indiceDeLigne > m)// Boucle permettant de sauter les n lignes correspondantes au trajet composé	
		{
			for(int i (0) ; i<=nbTrajetsComposants; i++)
			{
				fichier.getline(ligneCourante,TAILLE);
			}
			continue; // Le continue est la clé puisqu'après avoir décalé le curseur dans le fichier, il nous permet de recommencer la boucle.
		}
		TrajetCompose * trajetCompose = new TrajetCompose(); 
		for(int j (0); j <nbTrajetsComposants; j++)
		{
			fichier.getline(ligneCourante,TAILLE);
			TrajetSimple * trajetSComposant = CreationTrajetSimple(ligneCourante);
			trajetCompose->AjouterSousTrajet(trajetSComposant);
			delete trajetSComposant;
		}
		this->Ajouter(trajetCompose);
		delete trajetCompose;
	} 
	fichier.getline(ligneCourante,TAILLE);
  }
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ( const Catalogue & unCatalogue )
// Algorithme :
//     Alloation de mémoire pour le nouveau Catalogue,
//     puis copie en surface
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Catalogue>" << endl;
    #endif

    leCatalogue = new VecteurTrajet;
    *leCatalogue = *unCatalogue.leCatalogue;
} //----- Fin de Catalogue (constructeur de copie)


Catalogue::Catalogue ()
// Algorithme :
//     Allocation de mémoire pour le nouveau Catalogue
{
    #ifdef MAP
        cout << "Appel au constructeur de <Catalogue>" << endl;
    #endif

    leCatalogue = new VecteurTrajet;
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//     Libére la mémoire allouée pour leCatalogue
{
    #ifdef MAP
        cout << "Appel au destructeur de <Catalogue>" << endl;
    #endif

    delete leCatalogue;

} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
TrajetSimple * Catalogue::CreationTrajetSimple(char * ligne)
{
	char * villeDepart;
	char * villeArrivee;
	MoyenTransport moyenDeTransport;
	villeDepart = strtok(ligne,",");
	villeDepart = strtok(NULL,",");  //On supprime le début de ligne (numLigne et typeTrajet).
	villeDepart = strtok(NULL,",");
	villeArrivee = strtok(NULL,",");
	moyenDeTransport = (MoyenTransport) stoi(strtok(NULL,","));
	TrajetSimple * trajet = new TrajetSimple(villeDepart,villeArrivee,moyenDeTransport);
	return trajet;
}

bool Catalogue::VerificationsInfoTrajet(const Trajet & trajet, const string & villeDep, const string & villeArr) const
{
	if(!strcmp(villeDep.c_str(),"-")){
		if(!strcmp(villeArr.c_str(),"-")) return true;
		else if(!strcmp(trajet.GetArrivee(),villeArr.c_str())) return true;
		else return false;
	}
	else if(!strcmp(villeArr.c_str(),"-")){
		if(!strcmp(trajet.GetDepart(),villeDep.c_str())) return true;
		else return false;
	}
	else if(!strcmp(trajet.GetDepart(),villeDep.c_str()) && !strcmp(trajet.GetArrivee(),villeArr.c_str()))
	{
		return true;
	}
	else
	{
		return false;
	}

}


