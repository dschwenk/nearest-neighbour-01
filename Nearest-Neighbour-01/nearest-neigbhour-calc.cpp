#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>

#include "vector.h"
#include "nearest-neigbhour-calc.h"

using namespace std;



int calcNearstNeighbour(Vector* refVektor){	
	// stream zur Datei + Datei oeffnen
	ifstream file("points.txt",ios::in);
	if (file.is_open()){

		// Summe Abstand, Summe kleinster Abstand
		float sum = 0;
		float smallestsum = 1000;
		
		Vector* NearestVektor = new Vector(false);
		Vector* FileVektor = new Vector(false);
		
		// es wird zeilenweise aus Datei gelesen und jeweils in line gespeichert
		string line;

		// Datei zeilenweise auslesen
		while(getline(file,line)){
			
			// http://stackoverflow.com/questions/1894886/parsing-a-comma-delimited-stdstring
			// parse String - add elements to Vektor
			stringstream ss(line);
			float punkt = 0;
			int i = 0;
			//while((ss >> punkt) && i < ElementeJeVektor){
			while(i < ElementeJeVektor){
				// floats parsen und dem FileVektor anfuegen
				ss >> punkt;
				FileVektor->setPoint(punkt);
				if(ss.peek() == ','){
					ss.ignore();
				}
				i++;
			}
			// Klasse parsen und in FileVektor speichern
			int fileclas = -1;
			ss >> fileclas;
			FileVektor->setClas(fileclas);

			// berechene Abstand
			for(int i=0;i<ElementeJeVektor;i++){
				sum += (refVektor->getPoint(i) - FileVektor->getPoint(i)) * (refVektor->getPoint(i) - FileVektor->getPoint(i));
			}

			// Abstand kleiner als bisher, Vektor zuruecksetzen und mit neuen Daten (Daten vom naehsten vektor) fuellen
			if(sum < smallestsum){
				NearestVektor->clear();
				for(int i = 0;i<ElementeJeVektor;i++){
					NearestVektor->setPoint((FileVektor->getPoint(i)));
				}
				NearestVektor->setClas(FileVektor->getClas());
				smallestsum = sum;
			}
			FileVektor->clear();
			sum = 0;
		}

		// Datei schlieﬂen, naehster Vektor und Klasse ausgeben
		file.close();
		cout << "\nDer naeheste Vektor ist: \n";
		NearestVektor->print();
		return NearestVektor->getClas();
	}
	else {
		cout << "Unable to open file";
		return -1;
	}
}