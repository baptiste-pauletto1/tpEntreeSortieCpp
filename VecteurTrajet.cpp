/*************************************************************************
                           VecteurTrajet  -  description
                             -------------------
    début                : 19/11/2018
    copyright            : (C) 2018 par Thiago Verny & Taoyang Liu
    e-mail               : thiago.verny@insa-lyon.fr
                           taoyang.liu@insa-lyon.fr
*************************************************************************/

//--Réalisation de la classe <VecteurTrajet> (fichier VecteurTrajet.cpp)--

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <fstream>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "VecteurTrajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
Trajet* VecteurTrajet::GetTrajet(int index) const
// Algorithme:
//     Renvoie le pointeur contenu à l'index index du Vecteur
{
	return lesTrajets[index];
}

int VecteurTrajet::GetNombreDeTrajets() const
// Algorithme :
//     Renvoie la valeur de l'attribut nombreDeTrajets
{
    return this->nombreDeTrajets;
}

void VecteurTrajet::Ajouter(const Trajet* unTrajet)
// Algorithme :
//     Vérifie que le vecteur n'est pas plein ;
//     si il est plein, réalloue le double de la taille.
//     Ajoute ensuite une copie du Trajet pointé par unTrajet au Vecteur
{
	if (nombreDeTrajets + 1 > tailleVecteur)
	{
		tailleVecteur *= 2;
		#ifdef MAP
			cout << "Realoccation automatique, nouvelle taille : ";
			cout << tailleVecteur << endl;
		#endif
		Trajet** nouvLesTrajets = new Trajet*[tailleVecteur];
		for (int i=0; i<nombreDeTrajets; i++)
		{
			nouvLesTrajets[i] = lesTrajets[i]->GetTrajet();
			delete lesTrajets[i];
		}
		delete [] lesTrajets;
		lesTrajets = nouvLesTrajets;
	}

	lesTrajets[nombreDeTrajets] = unTrajet->GetTrajet();
	nombreDeTrajets++;
		
} //----- Fin de Méthode

void VecteurTrajet::Afficher() const
// Algorithme :
//     Pour chaque Trajet du Vecteur, appel a la méthode Trajet::Afficher()
{
	for (int i=0; i<nombreDeTrajets; i++)
	{
		lesTrajets[i]->Afficher();
	}
}

void VecteurTrajet::Formater(ofstream & ofs) const
//Algorithme :
//
{
	for(int i (0); i<nombreDeTrajets; i++)
	{	
		ofs << i+1 << ',';
		lesTrajets[i]->Formater(ofs);
	}

}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
VecteurTrajet::VecteurTrajet ( const VecteurTrajet & unVecteurTrajet )
// Algorithme :
//     Copie profonde : la structure et les objets de la structure
//     sont recréées
{
	#ifdef MAP
	  	cout <<"Appel au constructeur de copie de <VecteurTrajet>"<< endl;
	#endif

	lesTrajets = new Trajet* [unVecteurTrajet.tailleVecteur];
	
	for (int i=0; i<unVecteurTrajet.nombreDeTrajets; i++)
	{
		lesTrajets[i] = unVecteurTrajet.lesTrajets[i]->GetTrajet();
	}

	nombreDeTrajets = unVecteurTrajet.nombreDeTrajets;
	tailleVecteur = unVecteurTrajet.tailleVecteur;
} //----- Fin de VecteurTrajet (constructeur de copie)


VecteurTrajet::VecteurTrajet (int tailleDepart)
// Algorithme :
//    Alloue de la mémoire pour la struture de données en fonction de
//    tailleDepart. Vérifie au préalable que tailleDepart est strictement
//    positif, et le rend positif si ce n'était pas le cas
{
	#ifdef MAP
		cout << "Appel au constructeur de <VecteurTrajet>" << endl;
	#endif
	
	if (tailleDepart > 0)
	{
		tailleVecteur = tailleDepart;
	}
	else
	{
		tailleVecteur = 1;
	}

	lesTrajets = new Trajet* [tailleVecteur];
	nombreDeTrajets = 0;
} //----- Fin de VecteurTrajet


VecteurTrajet::~VecteurTrajet ( )
// Algorithme :
//     Détruit les objets contenus dans la structure de données
//     puis détruit la structure
{
	#ifdef MAP
		cout << "Appel au destructeur de <VecteurTrajet>" << endl;
	#endif

	for(int i=0; i<nombreDeTrajets; i++)
	{
		delete lesTrajets[i];
	}
	delete [] lesTrajets;
} //----- Fin de ~VecteurTrajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

