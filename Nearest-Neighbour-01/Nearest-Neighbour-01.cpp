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
	
	Vector* NaehsterVektor = new Vector(false);
	Vector* ReferenzVektor = new Vector(0,0,0,0);

	// Klasse des naehste Vektors
	int clas = 0;

	// benoetigt fuer Menuauswahl
	char inputChoice = '\0';


	while(true){
		cout << "Was wollen Sie tun?\n";
		cout <<	"v - Vektor anlegen und zur Datei hinzufuegen\n";
		cout << "l - Vektoren ausgeben\n";
		cout << "r - Referenzvektor anpassen\n";
		cout << "a - Referenzvektor ausgeben\n";
		cout << "n - Naehster Vektor berechnen\n";
		cout << "q - Programmende\n";
		cout << "Auswahl: ";

		cin >> inputChoice;

		switch(inputChoice){
			// neuer Vektor
			case 'v':
				newVector();
				break;
			// auflisten
			case 'l':
				printVectors();
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
				clas = calcNearstNeighbour(ReferenzVektor);
				cout << "\nKlasse: " << clas << "\n";
				break;
			// Verlassen
			case 'q':
				// Objekte loeschen
				delete ReferenzVektor;
				delete NaehsterVektor;
				return 0;
			default:
				cout << "\nUngueltige Eingabe!\n\n";
		}
	}	
	
	return 0;
}