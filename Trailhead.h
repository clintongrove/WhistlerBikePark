#ifndef TRAILHEAD_H_
#define TRAILHEAD_H_
#include <queue>
#include <set>
#include <typeinfo>
#include "IntermediateRider.h"
#include "BeginnerRider.h"
#include "AdvancedRider.h"
#include "Ticket.h"
#include "ChairLift.h"
class Trail;
class IntermediateRider;
class BeginnerRider;
class AdvancedRider;
class Rider;
class Trailhead{
public:
	ChairLift *lift;
	int num_served = 0;
	int total_wait = 0;
	std::queue<Rider*> trail_line;
	std::set<Trail*> the_trails;


	Trailhead(){ std::cout << " Trailhead default Constructed!" << std::endl; };
	Trailhead(std::set<Trail*> trails, Trailhead * next){
		this->the_trails = trails;
		lift->destination = next;
		lift->origin = this;
		std::cout << " Trailhead Constructed!" << std::endl;
	}
	void update(int clock){
		if (!trail_line.empty()){
			int wait_time;
			Trail *chosen;
			Rider * current = trail_line.front();
			chosen = current->choice(the_trails);//rider trail choice selection
			wait_time = clock - current->arrival_time;//updating ticket with current riders wait time
			current->pass.UpdateTrailhead(wait_time, this);


			double run_time = current->run(chosen);//calculate run time 
			current->pass.UpdateTrail(run_time, chosen);//record run time
			trail_line.pop();
			num_served++;
			total_wait += wait_time;
			current->arrival_time = clock;
			current->departure_time = clock;
			chosen->origin->lift->the_queue.push(current);
		}

	}
	void line(Rider* current){//@return void @param Rider* being pushed from chairlift to trailhead queue
		trail_line.push(current);

	}
};

#endif