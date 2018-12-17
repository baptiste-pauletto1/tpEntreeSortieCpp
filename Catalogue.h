/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 19/11/2018
    copyright            : (C) 2018 par Thiago Verny & Taoyang Liu
    e-mail               : thiago.verny@insa-lyon.fr
                           taoyang.liu@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "VecteurTrajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

// Rôle de la classe <Catalogue>
// =============================
// Permet de gérer l'affichage, l'ajout, et la recherche sur les Trajets

//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher ( ) const;
    // Mode d'emploi :
    //     
    // Contrat :
    //     Affiche l'ensemble des trajets contenus dans ce catalogue

    void Ajouter (const Trajet * t);
    // Mode d'emploi :
    //     const Trajet * t : un pointeur sur le Trajet à ajouter
    // Contrat :
    //     Ajoute le Trajet pointé par t au catalogue

    void RechercherSimple (const char* const* villeDepart, const char* const* villeDestination) const;
    // Mode d'emploi :
    //     const char* const* villeDepart : un pointeur sur une chaine de caractères 
    //                                      indiquant la ville de départ
    //     const char* const* villeArrivee : un pointeur sur une chaine de caractères 
    //                                      indiquant la ville de départ
    // Contrat :
    //     Recherche et affiche les Trajets entre villeDepart
    //     et villeArrivee, sans combinaison de trajets

    int Rechercher (const char* const* villeDepart, const char* const* villeDestination) const;
    // Mode d'emploi :
    //     const char* const* villeDepart : un pointeur sur une chaine de caractères 
    //                                      indiquant la ville de départ
    //     const char* const* villeArrivee : un pointeur sur une chaine de caractères 
    //                                      indiquant la ville de départ
    // Contrat :
    //     Recherche et affiche les trajets entre villeDepart
    //     et villeArrivee, directement ou par combinaison de Trajets

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Catalogue ( const Catalogue & unCatalogue );
    // Mode d'emploi (constructeur de copie) :
    //     const Catalogue & unCatalogue : référence sur le Catalogue à copier
    // Contrat :
    //     Réalise une copie en surface du Catalogue

    Catalogue ( );
    // Mode d'emploi :
    //
    // Contrat :
    //     Construit un Catalogue vide

    virtual ~Catalogue ( );
    // Mode d'emploi :
    //
    // Contrat :
    //     Détruit un Catalogue et libère la mémoire associée

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
VecteurTrajet * leCatalogue;

};

//-------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H

