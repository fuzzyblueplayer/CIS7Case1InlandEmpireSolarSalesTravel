#include "City.h"

int City::getDistance(string location) {
	if (location == "RS") {
		return toRiverside;
	}
	else if (location == "MV") {
		return toMoval;
	}
	else if (location == "HE") {
		return toHemet;
	}
	else {
		return toPerris;
	}
}