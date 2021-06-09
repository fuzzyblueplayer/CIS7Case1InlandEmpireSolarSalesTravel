#ifndef CITY_H
#define CITY_H
#include <iostream>
#include <string>

using namespace std;

class City {
private:
	string cityType;
	int toRiverside;
	int toMoval;
	int toHemet;
	int toPerris;
public:
	City() {
		cityType = "a";
		toRiverside = 0;
		toMoval = 0;
		toHemet = 0;
		toPerris = 0;
	}
	City(string place,int r,int m,int h,int p) {
		cityType = place;
		toRiverside = r;
		toMoval = m;
		toHemet = h;
		toPerris = p;
	}
	string getCity() { return cityType; }
	int getDistance(string location);
};



#endif