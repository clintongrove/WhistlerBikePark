#ifndef BEGINNERRIDER_H_
#define BEGINNERRIDER_H_
#include <iostream>
#include "Ticket.h"
#include "XCBicycle.h"
#include "EasyTrail.h"
#include "HardTrail.h"
#include "MedTrail.h"
#include "Trail.h"
#include "Rider.h"
#include <time.h>
class BeginnerRider: public Rider{
	friend class Trailhead;
private:
	double skill_lvl;
	double endurance;
	
	XCBicycle whip;
public:
	BeginnerRider(){
		srand(time(NULL));
		skill_lvl = rand() % 3;
		endurance = rand() % 10;
	}
	BeginnerRider(double skill, double enduro){
		skill_lvl = skill;
		endurance = enduro;
	}
	Ticket pass;
	Trail choice(std::set<Trail*> trails){
		std::set<Trail*> the_trails = trails;
		std::set<Trail*>::iterator it = the_trails.begin();
		while (it != the_trails.end()){
			if (typeid(MedTrail) == typeid(*it) || typeid(HardTrail) == typeid(*it)){
				the_trails.erase(it);
				it++;
			}
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
		double most=0;
		while (it != the_trails.end()){
			if ((*it)->difficulty > most){
				most = (*it)->difficulty;
				the_one = (*it);
				it++;
			}

		}
		return *the_one;
	}
};

#endif