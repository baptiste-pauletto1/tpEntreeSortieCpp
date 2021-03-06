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
    string nomFichier;
    string villeDep;
    string villeArr;
    int n;
    int m;
    Catalogue catalogueDesTrajets = Catalogue();

    do 
    {
        cout << "Que voulez-vous faire ?" << endl;
        cout << "1 - Ajouter un trajet au catalogue" << endl;
        cout << "2 - Afficher le catalogue" << endl;
        cout << "3 - Rechercher un parcours" << endl;
	cout << "4 - Lire un fichier catalogue" << endl;
	cout << "5 - Sauver un fichier catalogue" << endl;
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
			int moyenTmp;

                        cout << "Ajout d'un trajet simple" << endl;
                        cout << "Ville de départ : ";
                        cin >> depart;
                        cout << "Ville d'arrivée : ";
                        cin >> arrivee;
                        cout << "Moyen de transport: ";
                        scanf("%d", &moyenTmp);
			moyen = (MoyenTransport) moyenTmp;
                        cout << endl;
                        
                        TrajetSimple nouveauTrajet = TrajetSimple(depart, arrivee, moyen);
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
			int moyenTmp;
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
                            scanf("%d", &moyenTmp);
		            moyen = (MoyenTransport) moyenTmp;
                            cout << endl;

                           
                            TrajetSimple nouveauSousTrajet = TrajetSimple(depart, arrivee, moyen);
                            nouveauTrajet.AjouterSousTrajet(&nouveauSousTrajet);
                            nbTrajets++;

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
                    catalogueDesTrajets.RechercherSimple(depart, arrivee);
                }
                else
                {
                    catalogueDesTrajets.Rechercher(depart, arrivee);
                }
                delete [] depart;
                delete [] arrivee;
                break;
            }
	    case 4 :
		cout << "Commencez par entrer le nom du fichier (chemin d'accès)" << endl;
		cin >> nomFichier;
                cout << "Lecture fichier de données" << endl;
                cout << "1 - Lecture sans filtre" << endl;
                cout << "2 - Filtre de sélection selon le type de Trajet" << endl;
                cout << "3 - Filtre de sélection selon une ville de départ et/ou d'arrivée" << endl;
                cout << "4 - Filtre de sélection selon les indices des trajets" << endl;
                cout << "0 - Retour" << endl ;
                cin >> selection;
                switch (selection)
		{
			case 1:
				catalogueDesTrajets.Lire(nomFichier);
				cout << "Opération d'import terminée ! " << endl;
				break;
			case 2:
				cout << "Choix du type de Trajet" << endl;
				cout << "1 - Uniquement les trajets simples" << endl;
				cout << "2 - Uniquement les trajets composés" << endl;
				cin >> selection;
				switch(selection){
					case 1:
						catalogueDesTrajets.Lire(nomFichier,"TS");
						break;
					case 2:
						catalogueDesTrajets.Lire(nomFichier,"TC");
						break;
				}
				cout << "Opération d'import terminée ! " << endl;
				break;
			case 3:
				cout << "Choix de la ville de départ et/ou d'arrivée" << endl;
				cout << "Tapez un tiret (-) puis entrée pour ignorer un des deux champs" << endl;
				cout << "Premièrement, la ville de départ :" << endl;
				cin >> villeDep;
				cout << "Deuxièmement, la ville d'arrivée" << endl;
				cin >> villeArr;
				catalogueDesTrajets.Lire(nomFichier,villeDep,villeArr);
				cout << "Opération d'import terminée ! " << endl;
				break;
			case 4:
				cout << "Choix de l'intervalle de sélection [n,m]" << endl;
				cout << "Saisissez n, valeur minimale de l'intervalle" << endl;
				cin >> n;
				cout << "Saisissez m, valeur maximale de l'intervalle" << endl;
				cin >> m;
				catalogueDesTrajets.Lire(nomFichier,n,m);
				cout << "Opération d'import terminée ! " << endl;
				break;
		}
		break;
            case 5:
		cout << "Commencez par entrer le nom du fichier (chemin d'accès) du fichier de sauvegarde" << endl;
		cin >> nomFichier;
                cout << "Sauvegarde du catalogue" << endl;
                cout << "1 - Sauvegarde sans filtre" << endl;
                cout << "2 - Filtre de sélection selon le type de Trajet" << endl;
                cout << "3 - Filtre de sélection selon une ville de départ et/ou d'arrivée" << endl;
                cout << "4 - Filtre de sélection selon les indices des trajets" << endl;
                cout << "0 - Retour" << endl ;
                cin >> selection;
                switch (selection)
		{
			case 1:
				catalogueDesTrajets.Sauver(nomFichier);
				cout << "Opération de sauvegarde terminée ! " << endl;
				break;
			case 2:
				cout << "Choix du type de Trajet" << endl;
				cout << "1 - Uniquement les trajets simples" << endl;
				cout << "2 - Uniquement les trajets composés" << endl;
				cin >> selection;
				switch(selection){
					case 1:
						catalogueDesTrajets.Sauver(nomFichier,"TS");
						break;
					case 2:
						catalogueDesTrajets.Sauver(nomFichier,"TC");
						break;
				}
				cout << "Opération de sauvegarde terminée ! " << endl;
				break;
			case 3:
				cout << "Choix de la ville de départ et/ou d'arrivée" << endl;
				cout << "Tapez un tiret (-) puis entrée pour ignorer un des deux champs" << endl;
				cout << "Premièrement, la ville de départ :" << endl;
				cin >> villeDep;
				cout << "Deuxièmement, la ville d'arrivée" << endl;
				cin >> villeArr;
				catalogueDesTrajets.Sauver(nomFichier,villeDep,villeArr);
				cout << "Opération de sauvegarde terminée ! " << endl;
				break;
			case 4:
				cout << "Choix de l'intervalle de sélection [n,m]" << endl;
				cout << "Saisissez n, valeur minimale de l'intervalle" << endl;
				cin >> n;
				cout << "Saisissez m, valeur maximale de l'intervalle" << endl;
				cin >> m;
				catalogueDesTrajets.Sauver(nomFichier,n,m);
				cout << "Opération de sauvegarde terminée ! " << endl;
				break;
		}
		break;
	}
    }
    while (selection != 0);

    cout << "Au revoir ! " << endl;

	return 0;
} //----- fin de main

