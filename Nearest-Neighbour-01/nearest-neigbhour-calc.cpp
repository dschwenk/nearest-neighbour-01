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
		float smallestsum = 10000000000;
		
		Vector* NearestVektor = new Vector(false);
		Vector* FileVektor = new Vector(false);
		
		// es wird zeilenweise aus Datei gelesen und jeweils in line gespeichert
		string line;

		// Datei zeilenweise auslesen
		while(getline(file,line)){
			
			// http://stackoverflow.com/questions/1894886/parsing-a-comma-delimited-stdstring
			// parse String - Elemente zum Vektor hinzufuegen
			stringstream ss(line);
			float punkt = 0;
			int i = 0;
			while(i < ElementeJeVektor){
				ss >> punkt;
				FileVektor->addPoint(punkt);
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

			// ist Abstand kleiner als bisher, NaehsterVektor zuruecksetzen und mit neuen Daten (Daten vom naehsten Vektor) fuellen
			if(sum < smallestsum){
				NearestVektor->clear();
				for(int i = 0;i<ElementeJeVektor;i++){
					NearestVektor->addPoint((FileVektor->getPoint(i)));
				}
				NearestVektor->setClas(FileVektor->getClas());
				smallestsum = sum;
			}

			FileVektor->clear();
			sum = 0;
		}

		// Datei schlieﬂen, naehster Vektor ausgeben, Klasse zurueckgeben
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