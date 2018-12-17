/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 19/11/2018
    copyright            : (C) 2018 par Thiago Verny & Taoyang Liu
    e-mail               : thiago.verny@insa-lyon.fr
                           taoyang.liu@insa-lyon.fr
*************************************************************************/

//-- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <cstring>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
char* const* TrajetSimple::GetDepart () const
// Algorithme :
//     Renvoie un pointeur sur la chaine depart
{
    return &depart;
}


char* const* TrajetSimple::GetArrivee () const
// Algorithme :
//     Renvoie un pointeur sur la chaine arrivee
{
    return &arrivee;
}

void TrajetSimple::Afficher() const
// Algorithme :
//     Affiche les attributs depart, arrivee, et leMoyen
{
    cout << "----- Trajet Simple -----" << endl;
    cout << "Depart : " << depart << endl;
    cout << "Arrivee : " << arrivee << endl;
    cout << "Moyen de transport : " << leMoyen << endl;
    cout << "--- Fin Trajet Simple ---" << endl << endl;
}

Trajet* TrajetSimple::GetTrajet() const
// Algorithme :
//     renvoie un pointeur sur un nouveau trajet simple créé par copie
{
    return new TrajetSimple(*this);
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple )
// Algorithme :
//     Initialise depart et drrive par copie du contenu des chaines
//     de unTrajetSimple
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
    #endif

    depart = new char[strlen(unTrajetSimple.depart) + 1];
    strncpy(depart, unTrajetSimple.depart, strlen(unTrajetSimple.depart) + 1);

    arrivee = new char[strlen(unTrajetSimple.arrivee) + 1];
    strncpy(arrivee, unTrajetSimple.arrivee, strlen(unTrajetSimple.arrivee) + 1);

    leMoyen = unTrajetSimple.leMoyen;
} //----- Fin de TrajetSimple (constructeur de copie)

TrajetSimple::TrajetSimple (const char* const* villeDepart, const char* const* villeArrivee, const MoyenTransport moyen)
// Algorithme :
//     Initialise depart et drrive par copie du contenu des chaines pointées
//     par villeDepart et villeArrivée
{
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetSimple>" << endl;
    #endif
 
    depart = new char[strlen(*villeDepart) + 1];
    strncpy(depart, *villeDepart, strlen(*villeDepart) + 1);

    arrivee = new char[strlen(*villeArrivee) +1];
    strncpy(arrivee, *villeArrivee, strlen(*villeArrivee) + 1);

    leMoyen=moyen;
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
// Algorithme :
//     Libère la mémoire pour les 2 chaines de caractères utilisées
{
    #ifdef MAP
        cout << "Appel au destructeur de <TrajetSimple>" << endl;
    #endif

    delete [] depart;
    delete [] arrivee;
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

