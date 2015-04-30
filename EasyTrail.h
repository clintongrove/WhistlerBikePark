#ifndef EASYTRAIL_H_
#define EASYTRAIL_H_
#include <iostream>
#include "Trailhead.h"
class EasyTrail: public Trail{

public:
	EasyTrail(){}
	EasyTrail(double hard, double length, Trailhead * start, Trailhead * stop){
		this->difficulty = hard;
		this->distance = length;
		this->destination = stop;
		this->origin = start;
	}
	bool inuse;
	double difficulty;
	double distance;
	Trailhead *destination;
	Trailhead *origin;
};

#endif