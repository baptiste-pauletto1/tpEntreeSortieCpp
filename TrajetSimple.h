/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 19/11/2018
    copyright            : (C) 2018 par Thiago Verny & Taoyang Liu
    e-mail               : thiago.verny@insa-lyon.fr
                           taoyang.liu@insa-lyon.fr
*************************************************************************/

//-- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ------
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
enum MoyenTransport {Avion,Bus,Bateau,Train,Auto};

//------------------------------------------------------------------------

// Rôle de la classe <TrajetSimple>
// ================================
// Permet de gérer un trajet simple

//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual char* GetDepart () const;
    // Mode d'emploi :
    // 
    // Contrat :
    //     Renvoie un pointeur sur une chaine de caractère
    //     contenant la ville de départ du trajet
    
    virtual char* GetArrivee() const;
    // Mode d'emploi :
    // 
    // Contrat :
    //     Renvoie un pointeur sur une chaine de caractère
    //     contenant la ville d'arrivée du trajet
    
    virtual void Afficher () const;
    // Mode d'emploi :
    // 
    // Contrat :
    //     Affiche les caractéristiques du trajet

    virtual void Formater (ofstream & ofs) const;
    // Mode d'emploi :
    // 
    // Contrat :
    //     Formate les caractéristiques du trajet simple

    virtual Trajet* GetTrajet() const;
    // Mode d'emploi :
    // 
    // Contrat :
    //     Renvoie un pointeur sur un nouveau Trajet créé par copie
    

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple ( const TrajetSimple & unTrajetSimple );
    // Mode d'emploi (constructeur de copie) :
    //     const TrajetSimple & unTrajetSimple : référence sur un trajet
    //     simple à copier
    // Contrat :
    //     Crée un nouveau trajet simple par copie de unTrajetSimple

    TrajetSimple (const char* villeDepart, const char* villeArrivee, const MoyenTransport moyen); 
    // Mode d'emploi :
    //     const char* const* villeDepart : pointeur sur une chaine
    //         de caractères indiquant la ville de départ du trajet
    //     const char* const* villeArrivee : pointeur sur un chaine
    //         de caractèresindiquant la ville d'arrivée du trajet
    //     const MoyenTransport moyen : une constante le l'énumération
    // Contrat :
    //     Crée un nouveau trajet simple, de villeDepart à villeArrivee en moyen

    virtual ~TrajetSimple ( );
    // Mode d'emploi :
    //
    // Contrat :
    //     Détruit le trajet simple et sa mémoire associée

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
char* depart;
char* arrivee;
MoyenTransport leMoyen;
};

//------------------------Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H

