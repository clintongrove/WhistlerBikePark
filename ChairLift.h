#ifndef CHAIRLIFT_H_
#define CHAIRLIFT_H_
class Trailhead;
#include "Rider.h"
#include <queue>

class ChairLift{

public:
	Rider * current=NULL;
	std::queue<Rider*>the_queue;
	Trailhead *destination;
	Trailhead *origin;
	int num_served = 0;
	int total_wait = 0;
	int ride = 5;
	ChairLift(){};
	ChairLift(Trailhead*d, Trailhead*o){
		this->destination = d;
		this->origin = o;
		std::cout << " chairlift Constructed!" << std::endl;
	}
	void update(int clock){
		if (!the_queue.empty()){
			current = the_queue.front();
			current->pass.checkvalid(clock);
			if (current->pass.valid == true){
				current->departure_time = (clock - ride);
				if (clock > current->departure_time){

					int wait_time = current->departure_time - current->arrival_time;
					current->pass.UpdateChairLift(wait_time, this);
					++num_served;
					total_wait += wait_time;
					the_queue.pop();
					pushrider();
				}
			}
			else{
				the_queue.pop();

			}
		}
	}
	void pushrider();
};

#endif