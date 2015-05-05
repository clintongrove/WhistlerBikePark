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
	int num_served = 0;
	int total_wait = 0;
	int ride = 5;
	void update(int clock){
		if (!the_queue.empty()){
		Rider * current = the_queue.front();
		current->departure_time = current->arrival_time;
		int wait_time = current->departure_time-current->arrival_time;
		
		
		
		
		current->pass.UpdateChairLift(wait_time, this);

		++num_served;
		total_wait += wait_time;

		if (clock - current->arrival_time > wait_time + ride){
			the_queue.pop();
			destination->trail_line.push(current);

		}
		}
	}
};

#endif