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
	std::queue<Rider*> trail_line;
	std::set<Trail*> the_trails;
	Trailhead(){}
	Trailhead(std::set<Trail*> trails, ChairLift *l){
		this->the_trails = trails;
		this->lift = l;
	}
	void get_next(){
		Trail *chosen;
		Rider * current = trail_line.front();
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
		Trailhead::Descend(current, chosen);
	}
	void Descend(Rider *r, Trail *t,int clock){
		
		r->pass.UpdateTrailhead(wait_time,this);
		trail_line.pop();

	}
};

#endif