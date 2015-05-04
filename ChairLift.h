#ifndef CHAIRLIFT_H_
#define CHAIRLIFT_H_
class Trailhead;
class Rider;
#include <queue>
class ChairLift{

public:
	ChairLift(Trailhead*d, Trailhead*o){
		this->destination = d;
		this->origin = o;
	}
	std::queue<Rider*>the_queue;
	Trailhead *destination;
	Trailhead *origin;
	void update(int clock){


	}
};

#endif