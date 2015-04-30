#ifndef TRAILHEAD_H_
#define TRAILHEAD_H_
#include "ChairLift.h"
#include "Rider.h"
#include "BeginnerRider.h"
#include "AdvancedRider.h"
#include "IntermediateRider.h"
#include <queue>
#include <vector>
#include <time.h>
#include <set>

class Trailhead{
private:
	ChairLift *lift;
	Trail * descent;
	std::queue<Rider*> trail_line;
	std::set<Trail*> the_trails;
public:
	Trailhead(){}
	Trailhead(std::set<Trail*> trails){
		this->the_trails = trails;}
	void get_next(){
		Rider * current;
		if (typeid(trail_line.front()) == typeid(BeginnerRider))
			dynamic_cast<BeginnerRider*>(current);
		if (typeid(trail_line.front()) == typeid(IntermediateRider))
			dynamic_cast<IntermediateRider*>(current);
		if (typeid(trail_line.front()) == typeid(AdvancedRider))
			dynamic_cast<AdvancedRider*>(current);

		Trail chosen = current->choice(the_trails);


	}
	void Descend(Rider *r, Trail *t){
		//timestamp pass
		trail_line.pop();

	}

};

#endif