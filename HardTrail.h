#ifndef HARDTRAIL_H_
#define HARDTRAIL_H_
#include <iostream>
#include "Trailhead.h"
class HardTrail : public Trail{

public:
	HardTrail(){}
	HardTrail(double hard, double length, Trailhead * start, Trailhead * stop){
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