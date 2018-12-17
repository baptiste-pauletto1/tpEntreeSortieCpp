/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 19/11/2018
    copyright            : (C) 2018 par Thiago Verny & Taoyang Liu
    e-mail               : thiago.verny@insa-lyon.fr
                           taoyang.liu@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//----------------- -------------------------------------------------------

// Rôle de la classe <Trajet>
// ==========================
// Classe ancêtre

//------------------------------------------------------------------------

class Trajet 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual char* const* GetDepart() const = 0;
    // Mode d'emploi :
    //
    // Contrat :
    //     Retourne un pointeur sur une chaine de caractères indiquant
    //     la ville de départ du Trajet


    virtual char* const* GetArrivee() const = 0;
    // Mode d'emploi :
    //
    // Contrat :
    //     Retourne un pointeur sur une chaine de caractères indiquant
    //     la ville d'arrivée du Trajet

    virtual void Afficher() const = 0;
    // Mode d'emploi :
    //
    // Contrat :
    //     Affiche les caractéristiques d'un Trajet

    virtual Trajet* GetTrajet() const = 0;
    // Mode d'emploi :
    //
    // Contrat :
    //     Retourne un pointeur sur un nouvel objet correspondant
    //     à une copie de l'objet actuel
//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    Trajet ( const Trajet & unTrajet );
    // Mode d'emploi (constructeur de copie) :
    //     const Trajet & unTrajet : référence sur un Trajet
    // Contrat :
    //     Crée un copie en profondeur de l'objet Trajet

    Trajet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //     Crée un trajet vide

    virtual ~Trajet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //     Détruit un trajet et libère la mémoire associée

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//----------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H

