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
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

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

void Catalogue::RechercherSimple (const char* const* villeDepart, const char* const* villeDestination) const
// Algorithme :
//     Pour chacun des Trajets du Catalogue, compare les villes de départ
//     et d'arrivée avec celles passées en paramètre, et affiche le Trajet 
//     en cas d'égalité
{
    bool trouve = false;
    cout << "======= Recherche Simple =======" << endl;
    for (int i=0; i<leCatalogue->GetNombreDeTrajets(); i++)
    {
        if (strcmp(*villeDepart, *(leCatalogue->GetTrajet(i)->GetDepart())) == 0
	        && strcmp(*villeDestination, *(leCatalogue->GetTrajet(i)->GetArrivee())) == 0 )
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

int Catalogue::Rechercher (const char* const* villeDepart, const char* const* villeDestination) const
// Algorithme :
//     Pour chaque trajet, si la ville de départ correspond, alors
//     on trouve toutes les combinaisons de trajets pouvant mener à
//     la ville de destination
{
    if (strcmp(*villeDepart, *villeDestination) != 0)
    {
        char* villesVisitees[100];
        int nbVillesVisitees = 0;

        bool pasDeTrajets = true;
        bool dejaVisite = false;

        for (int i=0; i<leCatalogue->GetNombreDeTrajets(); i++)
        {
            if (strcmp(*villeDepart, *(leCatalogue->GetTrajet(i)->GetDepart())) == 0)
            // les trajets qui partent de villeDepart
            {
                dejaVisite = false;
                for (int j=0; i<nbVillesVisitees; i++)
                {
                    if (strcmp(*(leCatalogue->GetTrajet(i)->GetArrivee()), villesVisitees[j]) == 0)
                    {
                        dejaVisite = true;
                    }
                }
                if (!dejaVisite)
                {
                    pasDeTrajets = false;
                    leCatalogue->GetTrajet(i)->Afficher();
                    villesVisitees[nbVillesVisitees++] = *(leCatalogue->GetTrajet(i)->GetArrivee());
                    char* nouveauDepart = *(leCatalogue->GetTrajet(i))->GetArrivee();
                    this->Rechercher(&nouveauDepart, villeDestination);
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

void Lire (const string nomDuFichier)
// Algorithme :
//     
{
  ifstream fichier (nomDuFichier);
  if ( ! fichier)
  {
    cerr << "Erreur d'ouverture du fichier <" << nomDuFichier << ">" <<endl;
  }
  string valeurCourante;
  get(valeurCourante,2);// Nombre maximal de trajets dans le catalogue stocké : 99
  int nbTrajets = stoi(valeurCourante); 
  for(int i(0) ; i<nbTrajets ; i++)
  {
	getline(valeurCourante,100,','); //Supprime l'indice de la ligne
   	while(valeurCourante != '\n')
	{
		getline(valeurCourante,100,','); // Récupère le type de Trajet
		if(valeurCourante == "TS")
		{
			TrajetSimple * trajetS = creationTrajetSimple(fichier);
			this->Ajouter(trajetS);
		}
		else 
		{
			getline(valeurCourante,100,',') // Recupère le nombre de trajets composants le trajet composé
			int nbTrajetsComposants = stoi(valeurCourante);
			TrajetCompose * trajetCompose = new TrajetCompose(); 
			for(int j (0); j < nbTrajetsComposants; i++)
			{
				TrajetSimple * trajetSComposant = creationTrajetSimple(fichier);
				trajetCompose->AjouterSousTrajet(trajetSComposant);
			}
			this->Ajouter(trajetCompose);
		} 
  	}
  }
}

void Lire (const string nomDuFichier, const string & typeDeTrajet);

void Lire (const string nomDuFichier, const string & villeDepart, const string & villeArrivee); 
// faire un test, si un des deux = "" alors que l'autre sera considéré, sinon les deux.

void Lire (const string nomDuFichier, unsigned int n, unsigned int m);

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
TrajetSimple & Catalogue::creationTrajetSimple(ifstream & fluxFichier)
{
	string villeDepart;
	string villeArrivee;
	string moyenDeTransport;
	getline(villeDepart,100,',');
	getline(villeArrivee,100,',');
	getline(moyenDeTransport,100,',');

	TrajetSimple * trajet = new TrajetSimple(villeDepart,villeArrivee,stoi(moyenDeTransport));
	return trajet;
}


