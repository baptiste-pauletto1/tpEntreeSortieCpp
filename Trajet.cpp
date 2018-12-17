/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 19/11/2018
    copyright            : (C) 2018 par Thiago Verny & Taoyang Liu
    e-mail               : thiago.verny@insa-lyon.fr
                           taoyang.liu@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//--------------------------------------------------Surcharge d'operateurs

//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet ( const Trajet & unTrajet )
{
    #ifdef MAP
	    cout << "Appel au constructeur de copie de <Trajet>" << endl;
    #endif
}

Trajet::Trajet ( )
{
    #ifdef MAP
        cout << "Appel au constructeur de <Trajet>" << endl;
    #endif
}

Trajet::~Trajet ( )
{
    #ifdef MAP
        cout << "Appel au destructeur de <Trajet>" << endl;
    #endif
} 


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

