// Nearest-Neighbour-01.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "vector.h"
#include "nearest-neigbhour-calc.h"


int main(){
	
	// Maximal Anzahl an Vektoren
	const int MAXANZAHLVEKTOREN = 10;
	// aktuelle Anzahl an Vektoren
	int AnzahlVektoren = 0;

	Vector* VektorArray[MAXANZAHLVEKTOREN];

	Vector* NaehsterVektor = new Vector(false);
	Vector* ReferenzVektor = new Vector(0,0,0,0);

	// initialisiere Arrays mit NULL
	for(int i = 0;i<AnzahlVektoren;i++){
		VektorArray[i] = NULL;
	}

	// benoetigt fuer Menuauswahl
	char inputChoice = '\0';


	while(true){
		cout << "Was wollen Sie tun?\n";
		cout <<	"p - Vektor anlegen\n";
		cout << "l - Vektoren ausgeben\n";
		cout << "r - Referenzvektor anpassen\n";
		cout << "a - Referenzvektor ausgeben\n";
		cout << "n - Naehster Vektor berechnen\n";
		cout << "q - Programmende\n";
		cout << "Auswahl: ";

		cin >> inputChoice;

		switch(inputChoice){
			// neuer Punkt
			case 'p':
				if(AnzahlVektoren < MAXANZAHLVEKTOREN){
					VektorArray[AnzahlVektoren] = new Vector();
					AnzahlVektoren++;
					cout << "\n";
				}
				else {
					cout << "\nMaximal Anzahl an Vektoren erreicht!\n\n";
				}
				break;
			// auflisten
			case 'l':
				// sind Medien vorhanden?
				if(AnzahlVektoren != 0){
					cout << "\nVektoren: \n";
					for(int i=0;i<AnzahlVektoren;i++){
						VektorArray[i]->print();
					}
					cout << "\n";
				}
				else {
					cout << "\nKeine Vektoren vorhanden.\n\n";
				}
				break;
			// Referenzvektor anpassen
			case 'r':
				ReferenzVektor->setPoints();
				// ReferenzVektor->setClas();
				cout << "\nReferenzvektor angepasst.\n\n";
				break;
			case 'a':
				cout << "\nReferenzVektor: \n";				
				ReferenzVektor->print();
				cout << "\n";
				break;
			case 'n':
				NaehsterVektor = calcNearstNeighbour(ReferenzVektor, *VektorArray, AnzahlVektoren);
				cout << "\nNaehester Vektor: \n";
				NaehsterVektor->print();
				cout << "\n";
				break;
			// Verlassen
			case 'q':
				// Objekte loeschen
				for(int i=0;i<AnzahlVektoren;i++){
					delete VektorArray[i];
				}
				return 0;
			default:
				cout << "\nUngueltige Eingabe!\n\n";
		}
	}	
	
	return 0;
}