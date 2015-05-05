#ifndef TRAILHEAD_H_
#define TRAILHEAD_H_
class Trail;
class ChairLift;
class IntermediateRider;
class BeginnerRider;
class AdvancedRider;
class Rider;
#include "Ticket.h"
#include <queue>
#include <set>
#include <typeinfo>
#include "IntermediateRider.h"
#include "BeginnerRider.h"
#include "AdvancedRider.h"
#include "ChairLift.h"
class Trailhead{
public:
	ChairLift *lift;
	int num_served=0;
	int total_wait=0;
	std::queue<Rider*> trail_line;
	std::set<Trail*> the_trails;
	Trailhead(){}
	Trailhead(std::set<Trail*> trails, ChairLift *l){
		this->the_trails = trails;
		this->lift = l;
	}
	void update(int clock){
		if (!trail_line.empty()){
			int wait_time;
			Trail *chosen;
			Rider * current = trail_line.front();
			//rider trail choice selection
			if (typeid(trail_line.front()) == typeid(BeginnerRider)){
				BeginnerRider * b = dynamic_cast<BeginnerRider*>(current);
				Trail chosen = b->choice(the_trails);
			}
			if (typeid(trail_line.front()) == typeid(IntermediateRider)){
				IntermediateRider * r = dynamic_cast<IntermediateRider*>(current);
				Trail chosen = r->choice(the_trails);
			}
			if (typeid(trail_line.front()) == typeid(AdvancedRider)){
				AdvancedRider * a = dynamic_cast<AdvancedRider*>(current);
				Trail chosen = a->choice(the_trails);
			}
			
			wait_time = clock - current->arrival_time;//updating ticket with current riders wait time
			current->pass.UpdateTrailhead(wait_time, this);

			
			double run_time = current->run(chosen);//calculate run time 
			current->pass.UpdateTrail(run_time,chosen);//record run time
			num_served++;
			total_wait += wait_time;

			trail_line.pop();//pushes rider from trailhead queue to chairlift queue, updating arrival time
			current->arrival_time = clock;
			lift->the_queue.push(current);
			lift->update(clock);
			}

		}

		


};

#endif