#ifndef HARDTRAIL_H_
#define HARDTRAIL_H_
class Trailhead;
#include "Trail.h"
class HardTrail : public Trail{

public:
	HardTrail(Trailhead*d, Trailhead*o, double dist, double diff) :Trail(d, o, dist, diff){}
	bool inuse;
	double difficulty;
	double distance;
	Trailhead *destination;
	Trailhead *origin;
};

#endif