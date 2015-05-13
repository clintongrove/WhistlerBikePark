#ifndef BEGINNERRIDER_H_
#define BEGINNERRIDER_H_
class HardTrail;
class MedTrail;
class EasyTrail;
#include<iostream>
#include <time.h>
#include <set>
#include <iterator>
#include <vector>
#include <algorithm>
#include "Rider.h"
#include "Trail.h"
#include "XCBicycle.h"
#include "Ticket.h"
#include<time.h>
class BeginnerRider : public Rider{
friend class Trailhead;
public:
	BeginnerRider(double skill, double enduro, int ticket, int clock) :Rider(skill, enduro, ticket, clock){ whip = new XCBicycle(); }
	Trail* choice(std::set<Trail*>the_trails){
		std::vector<Trail*> rider_trails;
		for (std::set<Trail*>::iterator it = the_trails.begin(); it != the_trails.end(); it++){
			if (typeid(*it) == typeid(MedTrail) || typeid(*it) == typeid(HardTrail)){
				continue;
			}
			if (this->skill_lvl < (*it)->difficulty){
				continue;
			}
			else if ((*it)->inuse == 1){
				continue;
			}
			else{
				rider_trails.push_back(*it);
				continue;
			}
		}
		double most = 0;
		int the_one = 0;
		for (int i = 0; i < rider_trails.size(); ++i){
			if (most>rider_trails[i]->difficulty){
				continue;
			}
			else{
				most = rider_trails[i]->difficulty;
				the_one = i;
				continue;
			}
		}
		return (rider_trails[the_one]);
	}
	double run(Trail* t){
		double active, passive, mechanical;
		int length = t->distance;
		double end = length - endurance;

		mechanical = whip.mechanical();
		if (mechanical == 0)
			passive = (length - end) / (skill_lvl * 3);
		else{
			srand(time(NULL));
			end = rand() % length;
			mechanical = (length - end) / 3;
			active = (end) / (skill_lvl * 3);
		}
		return active + passive + mechanical;
	}


};

#endif