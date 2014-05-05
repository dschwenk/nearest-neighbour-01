#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "vector.h"
#include "nearest-neigbhour-calc.h"

using namespace std;



Vector* calcNearstNeighbour(Vector* refVektor, Vector* arrVektor, int AnzahlVektoren){
	
	Vector* NearestVektor = new Vector(false);
	float sum = 0;
	float smallestsum = 1000;
	cout << "1";

	for(int j=0;j<AnzahlVektoren;j++){
		for(int i=0;i<ElementeJeVektor;i++){
			cout << "rechne - j: " << j << "   i: " << i << "\n";
			// (Xi - Yi) im Quardart, keine Wurzel
			// sum += (refVektor->getPoint(i) - arrVektor[j].getPoint(i)) * (refVektor->getPoint(i) - arrVektor[j].getPoint(i));
			float x = refVektor->getPoint(i);
			float y = arrVektor[j].getPoint(i);
			float diff = x-y;
			float squad = diff * diff;
			sum += squad;
		}	
	
		if(sum < smallestsum){
			cout << "sum < smallestsum\n\n";
			*NearestVektor = arrVektor[j];
		}
		sum = 0;
	}	

	return NearestVektor;
}