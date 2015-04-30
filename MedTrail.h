#ifndef MEDTRAIL_H_
#define MEDTRAIL_H_
#include <iostream>
#include "Trailhead.h"
class MedTrail : public Trail{

public:
	MedTrail(){}
	MedTrail(double hard, double length, Trailhead * start, Trailhead * stop){
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