/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 19/11/2018
    copyright            : (C) 2018 par Thiago Verny & Taoyang Liu
    e-mail               : thiago.verny@insa-lyon.fr
                           taoyang.liu@insa-lyon.fr
*************************************************************************/

//--Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp)--

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
char* TrajetCompose::GetDepart( ) const
// Algorithme :
//     Renvoie un pointeur sur la chaine de caractère
//     contenant la ville de départ du premier trajet de la liste
{
   return laListe->GetTrajet(0)->GetDepart();
}

char* TrajetCompose::GetArrivee( ) const
// Algorithme :
//     Renvoie un pointeur sur la chaine de caractère
//     contenant la ville d'arrivée du dernier trajet de la liste
{
    return laListe->GetTrajet(nombreDeTrajets - 1)->GetArrivee();
}

void TrajetCompose::Afficher() const
// Algorithme :
//     Fait appel à la méthode VecteurTrajet::Afficher
{
    cout << "===== TRAJET COMPOSE =====" <<endl;
	laListe->Afficher();
	cout << "=== FIN TRAJET COMPOSE ===" << endl << endl;
}

void TrajetCompose::Formater(ofstream & ofs) const
{
    ofs << "TC" << ',' << laListe->GetNombreDeTrajets() << endl;
    laListe->Formater(ofs);
}

Trajet* TrajetCompose::GetTrajet() const
// Algorithme :
//     Retourne un nouvel objet TrajetComposé construit à partir
//     de l'objet actuel
{
    return new TrajetCompose(*this);
}

void TrajetCompose::AjouterSousTrajet(Trajet* t)
// Algorithme :
//     Vérifie que la ville de départ du nouveau sous-trajet
//     est la même que la ville d'arrivée du dernier trajet de la liste
//     Ajoute un sous trajet dans la liste de ce Trajet Composé
//     en faisant appel à la méthode VecteurTrajet::Ajouter()
{
    if (nombreDeTrajets == 0 
        || strcmp(t->GetDepart(), laListe->GetTrajet(nombreDeTrajets - 1)->GetArrivee()) == 0)
    {
        nombreDeTrajets++;
        laListe->Ajouter(t);
    }
    else
    {
        cerr << "Erreur : Ce sous trajet ne suit pas le précédent !" << endl;
    }
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose ( const TrajetCompose & unTrajetCompose )
// Algorithme :
//     Réalise une copie en profondeur du Trajet Composé actuel en
//     s'appuyant  sur le constructeur de copie de la classe VeteurTrajet
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
    #endif
    
    laListe = new VecteurTrajet(*unTrajetCompose.laListe);
    nombreDeTrajets = unTrajetCompose.nombreDeTrajets;
} //----- Fin de TrajetCompose (constructeur de copie)


TrajetCompose::TrajetCompose ( )
// Algorithme :
//     Instanciation d'un TrajetComposé vide
{
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetCompose> - initialisation vide" << endl;
    #endif

    this->laListe = new VecteurTrajet();
    this->nombreDeTrajets = 0;

} //----- Fin de TrajetCompose

TrajetCompose::TrajetCompose (const VecteurTrajet* uneListe)
// Algorithme :
//     Instanciation d'un Trajet Composé à partir d'un Vecteur de Trajets
{
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetCompose> - initialiasation avec un vecteur de trajets" << endl;
    #endif
    this->laListe = new VecteurTrajet(*uneListe);
    this->nombreDeTrajets = uneListe->GetNombreDeTrajets();
}

TrajetCompose::~TrajetCompose ( )
{
    #ifdef MAP
        cout << "Appel au destructeur de <TrajetCompose>" << endl;
    #endif

    delete laListe;
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

