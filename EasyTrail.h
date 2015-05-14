#ifndef EASYTRAIL_H_
#define EASYTRAIL_H_
class Trailhead;
#include "Trail.h"
class EasyTrail: public Trail{

public:
	EasyTrail(Trailhead*d, Trailhead*o, double dist, double diff) :Trail(d, o, dist, diff){}
};

#endif