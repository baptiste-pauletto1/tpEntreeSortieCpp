/*************************************************************************
                         VecteurTrajet - description
                             -------------------
    début                : 19/11/2018
    copyright            : (C) 2018 par Thiago Verny & Taoyang Liu
    e-mail               : thiago.verny@insa-lyon.fr
                           taoyang.liu@insa-lyon.fr
*************************************************************************/

//--- Interface de la classe <VecteurTrajet> (fichier VecteurTrajet.h) ---
#if ! defined ( VECTEURTRAJET_H )
#define VECTEURTRAJET_H

//--------------------------------------------------- Interfaces utilisées
#include"Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

// Rôle de la classe <VecteurTrajet>
// =================================
// Permet de gérer la structure de données qui stocke une collection
// de Trajets

//------------------------------------------------------------------------

class VecteurTrajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    Trajet* GetTrajet(int index) const;
    // Mode d'emploi :
    //     int index : index du Trajet dans le Vecteur
    //     Retour Trajet* : pointeur sur un Trajet
    // Contrat :
    //     Renvoie un pointeur sur le Trajet contenu à l'index index
    //     du Vecteur

    int GetNombreDeTrajets() const;
    // Mode d'emploi :
    //     Retour int : le nombre de Trajets contenus dans le Vecteur
    // Contrat :
    //     Renvoie le nombre de Trajets contenus dans le Vecteur

    void Ajouter(const Trajet* unTrajet);
    // Mode d'emploi :
    //     const Trajet* unTrajet : pointeur sur le Trajet à ajouter
    //                              au Vecteur
    // Contrat :
    //     Ajoute le Trajet pointé par unTrajet au Vecteur

    void Afficher() const;
    // Mode d'emploi :
    //
    // Contrat :
    //     Affiche les Trajets contenus dans le Vecteur

    void Formater(ofstream & ofs) const;
    // Mode d'emploi :
    //
    // Contrat :
    //     Formate les Trajets contenus dans le Vecteur

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    VecteurTrajet ( const VecteurTrajet & unVecteurTrajet );
    // Mode d'emploi :
    //     const VecteurTrajet & unVecteurTrajet :
	//         le VecteurTrajet à copier
    // Contrat :
    //     Crée un nouvel objet VecteurTrajet en copiant
    //     en profondeur unVecteurTrajet
    
    VecteurTrajet (int tailleDepart = 5);
    // Mode d'emploi :
    //     int tailleDepart : taille de la structure
    // Contrat :
    //     Crée un objet VecteurTrajet et alloue la mémoire pour la
    //     structure de données en fonction de tailleDepart

    virtual ~VecteurTrajet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //     La mémoire occupée par la structure de données et les objets
    //     contenus dans la structure est libérée

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
Trajet** lesTrajets;
int nombreDeTrajets;
int tailleVecteur;

};

//---------------------- Autres définitions dépendantes de <VecteurTrajet>

#endif // VECTEURTRAJET_H
