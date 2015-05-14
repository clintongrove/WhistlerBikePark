#ifndef TRAIL_H_
#define TRAIL_H_
class Trailhead;
class Trail{

public:
	bool inuse;
	double difficulty;
	double distance;
	Trailhead *destination = NULL;
	Trailhead *origin = NULL;

	Trail(Trailhead*d,Trailhead*o,double dist, double diff){
		this->destination = d;
		this->origin = o;
		this->inuse = 0;
		this->distance = dist;
		this->difficulty = diff;
	}

	~Trail()
	{
		if (destination == NULL)
			delete destination;
		if (origin == NULL)
			delete origin;
	}

};

#endif