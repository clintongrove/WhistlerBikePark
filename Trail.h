#ifndef TRAIL_H_
#define TRAIL_H_
class Trailhead;
class Trail{

public:
	Trail(Trailhead*d,Trailhead*o,double dist, double diff){
		this->destination = d;
		this->origin = o;
		this->inuse = 0;
		this->distance = dist;
		this->difficulty = diff;
	}
	bool inuse;
	double difficulty;
	double distance;
	Trailhead *destination;
	Trailhead *origin;
};

#endif