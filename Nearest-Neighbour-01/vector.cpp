#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "vector.h"

using namespace std;


Vector::Vector() {
	// Punkte einlesen
	cout << "\nBitte Koordinaten & Klasse eingeben: \n";
	for(int i=0;i<ElementeJeVektor;i++){
		float input = 0;
		do {
			// clear zum zuruecksetzen nach Fehler, sync um Puffer zu leeren
			cin.clear();
			cin.sync();
			cout << "Koordinate: ";
		}
		while(!(cin >> input) && cin.fail());
		v.push_back(input);
		// v.push_back(i); // Fügt i ans Ende von v an.
	}
	do {
		// clear zum zuruecksetzen nach Fehler, sync um Puffer zu leeren
		cin.clear();
		cin.sync();
		cout << "Klasse: ";
	}
	while(!(cin >> this->clas) && cin.fail());
}


Vector::Vector(bool b){
	// nothing to do
};


Vector::Vector(float a, float b, float c, int clas){
	this->v.push_back(a);
	this->v.push_back(b);
	this->v.push_back(c);
	this->clas = clas;
};


void Vector::setPoints(){
	// v.clear(); Entfernt alle Elemente aus v; leert v.
	this->v.clear();
	// Punkte einlesen
	cout << "\nBitte Punkte eingeben: \n";
	for(int i=0;i<ElementeJeVektor;i++){
		float input = 0;
		do {
			// clear zum zuruecksetzen nach Fehler, sync um Puffer zu leeren
			cin.clear();
			cin.sync();
			cout << "Koordinate: ";
		}
		while(!(cin >> input) && cin.fail());
		this->v.push_back(input);
		// v.push_back(i); // Fügt i ans Ende von v an.
	}
}


void Vector::setClas(){
	// Klasse einlesen
	cout << "\nBitte Klassen eingeben: \n";
	do {
		// clear zum zuruecksetzen nach Fehler, sync um Puffer zu leeren
		cin.clear();
		cin.sync();
		cout << "Klasse: ";
	}
	while(!(cin >> this->clas) && cin.fail());
}


void Vector::print(){
	// v[n]; Repräsentiert das n. Element in v (ohne zu prüfen, dass n existiert).
	int size = this->getSize();
	for(int i=0;i<size;i++){
		cout << left << setw(8) << v[i] << "  ";
	}
	cout << "|  " << this->clas;
	cout << "\n";
}


float Vector::getPoint(int i){
	return this->v[i];
}


int Vector::getSize(){
	// v.size(); Liefert die Anzahl aller Elemente in v.
	return this->v.size();
}

int Vector::getClas(){
	return this->clas;
}
