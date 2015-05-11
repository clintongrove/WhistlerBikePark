#ifndef INTERMEDIATERIDER_H_
#define INTERMEDIATERIDER_H_
class HardTrail;
#include<iostream>
#include <time.h>
#include <set>
#include <iterator>
#include <vector>
#include <algorithm>
#include "Rider.h"
#include "Trail.h"
#include "AMBicycle.h"
#include "Ticket.h"
class IntermediateRider : virtual public Rider{
	friend class Trailhead;
public:
	std::string name;
	double skill_lvl;
	double endurance;
	AMBicycle whip;
	Ticket pass;
	IntermediateRider(double skill, double enduro, int ticket, int clock) :Rider(skill, enduro, ticket, clock){}

	int arrival_time;
	int departure_time;
	Trail* choice(std::set<Trail*>the_trails){
		std::vector<Trail*> rider_trails;
		for (std::set<Trail*>::iterator it = the_trails.begin(); it != the_trails.end(); it++){
			if (typeid(HardTrail) == typeid(*it)){
				continue;
			}
			else if (this->skill_lvl < (*it)->difficulty){
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