#ifndef ADVANCEdRIDER_H_
#define ADVANCEDRIDER_H_
#include <iostream>
#include "Ticket.h"
#include "DHBicycle.h"
#include "EasyTrail.h"
#include "HardTrail.h"
#include "MedTrail.h"
#include "Trail.h"
#include "Rider.h"
#include <time.h>
class AdvancedRider : public Rider{
	friend class Trailhead;
private:
	double skill_lvl;
	double endurance;
	
	DHBicycle whip;
public:
	AdvancedRider(){
		srand(time(NULL));
		skill_lvl = 7+rand() % 3;
		endurance = rand() % 10;
	}
	AdvancedRider(double skill, double enduro){
		skill_lvl = skill;
		endurance = enduro;
	}
	Trail choice(std::set<Trail*> trails){
		std::set<Trail*> the_trails = trails;
		std::set<Trail*>::iterator it = the_trails.begin();
		while (it != the_trails.end()){
			if (this->skill_lvl < (*it)->difficulty){
				the_trails.erase(it);
				it++;
			}
			if ((*it)->inuse == 1){
				the_trails.erase(it);
				it++;
			}
			else
				it++;
		}
		it = the_trails.begin();
		Trail *the_one;
		double most = 0;
		while (it != the_trails.end()){
			if ((*it)->difficulty > most){
				most = (*it)->difficulty;
				the_one = (*it);
				it++;
			}

		}
		return *the_one;
	}
	Ticket pass;
};

#endif