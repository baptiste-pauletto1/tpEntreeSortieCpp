/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 19/11/2018
    copyright            : (C) 2018 par Thiago Verny & Taoyang Liu
    e-mail               : thiago.verny@insa-lyon.fr
                           taoyang.liu@insa-lyon.fr
*************************************************************************/

//--- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ---
#if ! defined ( TRAJET_COMPOSE_H )
#define TRAJET_COMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "VecteurTrajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//    Permet de gérer des trajets composés
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual char* const* GetDepart( ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //     Renvoie un pointeur sur une chaine contenant la ville
    //     de départ du trajet composé


    virtual char* const* GetArrivee( ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //     Renvoie un pointeur sur une chaine contenant la ville
    //     d'arrivée du trajet composé (la ville d'arrivée du dernier
    //     trajet de la liste)

    virtual void Afficher( ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //     Affiche l'ensemble des trajets composant le trajet composé

    virtual Trajet* GetTrajet() const;
    // Mode d'emploi :
    //
    // Contrat :
    //     Renvoie un pointeur sur un nouveau trajet créé par copie
    //     du trajet actuel

    void AjouterSousTrajet(Trajet* t);
    // Mode d'emploi :
    //     Trajet* t : un pointeur sur un trajet à ajouter à la suite
    //     de la liste de trajets. La ville de départ doit correspondre
    //     a la ville d'arrivée du dernier trajet de la liste
    // Contrat :
    //     Ajoute le trajet t à liste de trajets composant le trajet composé

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose ( const TrajetCompose & unTrajetCompose );
    // Mode d'emploi (constructeur de copie) :
    //     const TrajetCompose & unTrajetCompose : référence sur le trajet
    //     composé a copier pour la crétion du nouveau trajet composé
    // Contrat :
    //     Crée un nouveau trajet composé à partir de unTrajetCompose

    TrajetCompose ( );
    // Mode d'emploi :
    //
    // Contrat :
    //     Crée un nouveau trajet compose vide

    TrajetCompose (const VecteurTrajet* uneListe);
    // Mode d'emploi :
    //
    // Contrat :
    //     Crée un nouveau trajet composé à partie d'un VeteurTrajet

    virtual ~TrajetCompose ( );
    // Mode d'emploi :
    //
    // Contrat :
    //     Détruit et libère la mémoire du trajet composé

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
VecteurTrajet* laListe;
int nombreDeTrajets;

//---------------------- Autres définitions dépendantes de <TrajetCompose>
};
#endif // TRAJET_COMPOSE_H

