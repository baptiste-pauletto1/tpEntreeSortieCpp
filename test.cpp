/*************************************************************************
                 Test  -  Programme de test de l'application
                             -------------------
    début                : 19/11/2018
    copyright            : (C) 2018 par Thiago Verny & Taoyang Liu
    e-mail               : thiago.verny@insa-lyon.fr
                           taoyang.liu@insa-lyon.fr
*************************************************************************/

//---------- Réalisation du module <test> (fichier test.cpp) -------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "VecteurTrajet.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types
//---------------------------------------------------- Variables statiques
//------------------------------------------------------ Fonctions privées

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main (  )
{
    int selection;
    Catalogue catalogueDesTrajets = Catalogue();

    do 
    {
        cout << "Que voulez-vous faire ?" << endl;
        cout << "1 - Ajouter un trajet au catalogue" << endl;
        cout << "2 - Afficher le catalogue" << endl;
        cout << "3 - Rechercher un parcours" << endl;
	cout << "4 - Lire un fichier de Trajet" << endl;
        cout << "0 - Quitter" << endl ;
        cin >> selection;
        switch (selection)
        {
            case 1 :
            {
                cout << "Ajout de trajet" << endl;
                cout << "1 - Ajouter un trajet simple" << endl;
                cout << "2 - Ajouter un trajet composé" << endl;
                cout << "0 - Retour" << endl ;
                cin >> selection;
                switch (selection)
                {
                    case 1 :
                    {
                        char* depart = new char[101];
                        char* arrivee = new char[101];
                        MoyenTransport moyen;

                        cout << "Ajout d'un trajet simple" << endl;
                        cout << "Ville de départ : ";
                        cin >> depart;
                        cout << "Ville d'arrivée : ";
                        cin >> arrivee;
                        cout << "Moyen de transport: ";
                        scanf("%d", &moyen);
                        cout << endl;
                        
                        TrajetSimple nouveauTrajet = TrajetSimple(&depart, &arrivee, moyen);
                        catalogueDesTrajets.Ajouter(&nouveauTrajet);
                        
                        
                        delete [] depart;
                        delete [] arrivee;
                        selection = -1;
                        break;
                    }
                    case 2 :
                    {
                        char* depart = new char[101];
                        char* arrivee = new char[101];
                        MoyenTransport moyen;
                        int nbTrajets = 1;

                        cout << "Ajout d'un trajet composé" << endl;
                        TrajetCompose nouveauTrajet = TrajetCompose();
                        do
                        {
                            cout << "Sous-trajet n°" << nbTrajets << endl;
                            cout << "Ville de départ : ";
                            cin >> depart;
                            cout << "Ville d'arrivée : ";
                            cin >> arrivee;
                            cout << "Moyen de transport: ";
                            scanf("%d", &moyen);
                            cout << endl;

                            if (strcmp(depart, arrivee) != 0)
                            {
                                TrajetSimple nouveauSousTrajet = TrajetSimple(&depart, &arrivee, moyen);
                                nouveauTrajet.AjouterSousTrajet(&nouveauSousTrajet);
                                nbTrajets++;
                            }
                            else
                            {
                                cerr << "Erreur : ce sous-trajet ne va nulle part !" << endl;
                            } 

                            cout << "Ajouter un sous-trajet ? (1 : OUI; 0 : NON)" << endl;
                            cin >> selection;
                        } while (selection != 0);

                        catalogueDesTrajets.Ajouter(&nouveauTrajet);

                        delete [] depart;
                        delete [] arrivee;
                        selection = -1;
                        break;
                    }
                }
                selection = -1;
                break;
            }

            case 2 :
                catalogueDesTrajets.Afficher();
                break;

            case 3 :
            {
                char* depart = new char[101];
                char* arrivee = new char[101];
                bool methode;

                cout << "Recherche de parcours" << endl;
                cout << "Ville de départ : ";
                cin >> depart;
                cout << "Ville d'arrivée : ";
                cin >> arrivee;
                cout << "Méthode de recherche (0 : simple; 1 : avancée) "<< endl;
                cin >> methode;
                cout << endl;
                if (!methode)
                {
                    catalogueDesTrajets.RechercherSimple(&depart, &arrivee);
                }
                else
                {
                    catalogueDesTrajets.Rechercher(&depart, &arrivee);
                }
                delete [] depart;
                delete [] arrivee;
                break;
            }
	    case 4 :
		catalogueDesTrajets.Lire("demo.txt");
        }
    }
    while (selection != 0);

    cout << "Au revoir ! " << endl;

	return 0;
} //----- fin de main

