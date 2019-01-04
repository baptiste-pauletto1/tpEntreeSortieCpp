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
#include "TrajetSimple.h"
#include <fstream>

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
    void Afficher ( ) const; // si on met un flux en paramètre et qu'on formatte, on est alors capable de gérer la sauvegarde
    // Mode d'emploi :
    //     
    // Contrat :
    //     Affiche l'ensemble des trajets contenus dans ce catalogue

    void Ajouter (const Trajet * t);
    // Mode d'emploi :
    //     const Trajet * t : un pointeur sur le Trajet à ajouter
    // Contrat :
    //     Ajoute le Trajet pointé par t au catalogue

    void RechercherSimple (const char* villeDepart, const char* villeDestination) const;
    // Mode d'emploi :
    //     const char* const* villeDepart : un pointeur sur une chaine de caractères 
    //                                      indiquant la ville de départ
    //     const char* const* villeArrivee : un pointeur sur une chaine de caractères 
    //                                      indiquant la ville de départ
    // Contrat :
    //     Recherche et affiche les Trajets entre villeDepart
    //     et villeArrivee, sans combinaison de trajets

    int Rechercher (const char* villeDepart, const char* villeDestination) const;
    // Mode d'emploi :
    //     const char* const* villeDepart : un pointeur sur une chaine de caractères 
    //                                      indiquant la ville de départ
    //     const char* const* villeArrivee : un pointeur sur une chaine de caractères 
    //                                      indiquant la ville de départ
    // Contrat :
    //     Recherche et affiche les trajets entre villeDepart
    //     et villeArrivee, directement ou par combinaison de Trajets

    void Lire (const std::string nomDuFichier);
    // Mode d'emploi :
    //     const std::string nomDuFichier : Chaîne de caractères indiquant le chemin 
    //				    	    d'accès au fichier de sauvegarde 
    // Contrat :
    //     Les informations doivent être au bon format.

    void Lire (const std::string nomDuFichier, const string & typeDeTrajet);
    // Mode d'emploi :
    //     const std::string nomDuFichier : Chaîne de caractères indiquant le chemin 
    //				    	    d'accès au fichier de sauvegarde 
    //     const std::string typeDeTrajet : Chaîne de caractères indiquant le type 
    //				    	    de trajet souhaité. 
    // Contrat :
    //     Les informations doivent être au bon format.
	
    void Lire (const std::string nomDuFichier, const string & villeDepart, const string & villeArrivee);
    // Mode d'emploi :
    //     const std::string nomDuFichier : Chaîne de caractères indiquant le chemin 
    //				    	    d'accès au fichier de sauvegarde 
    //     const std::string villeDepart  : Chaîne de caractères indiquant la ville 
    //				    	    de départ des trajets souhaitée.
    //     const std::string villeArrivee : Chaîne de caractères indiquant la ville 
    //				    	    d'arrivée des trajets souhaitée.  
    // Contrat :
    //     Les informations doivent être au bon format.

    void Lire (const std::string nomDuFichier, unsigned int n, unsigned int m);
    // Mode d'emploi :
    //     const std::string nomDuFichier : Chaîne de caractères indiquant le chemin 
    //				    	    d'accès au fichier de sauvegarde 
    //
    //     const int n : variable entière donnant le numéro du premier trajet souhaité
    //     const int m : variable entière donnant le numéro du dernier trajet souhaité
    //
    // Contrat :
    //     Les informations doivent être au bon format.

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
    TrajetSimple * CreationTrajetSimple(char * ligne);
    // Mode d'emploi :
    //     Créé un trajet simple à partir d'une ligne extraite d'un fichier.
    //     char * ligne : Ligne contenant toutes les informations nécessaires à la 
    //                    création d'un trajet simple.
	
    bool VerificationsInfoTrajet(const Trajet & trajet, const string & villeDep, const string & villeArr) const;		    	    
    // Mode d'emploi :
    //     Vérifie la conformité des informations du trajet avant de l'ajouter.
    //     const string & villeDep : String contenant la ville de départ souhaitée 
    //                               pour la lecture filtrée.
    //     const string & villeArr : String contenant la ville d'arrivée souhaitée 
    //                               pour la lecture filtrée.

//----------------------------------------------------- Attributs protégés
VecteurTrajet * leCatalogue;

};

//-------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H

