#ifndef MEDTRAIL_H_
#define MEDTRAIL_H_
class Trailhead;
#include "Trail.h"
class MedTrail : public Trail{

public:
	MedTrail(Trailhead*d, Trailhead*o, double dist, double diff) :Trail(d,o,dist,diff){}
	bool inuse;
	double difficulty;
	double distance;
	Trailhead *destination;
	Trailhead *origin;
};

#endif