#ifndef RIDER_H_
#define RIDER_H_
class Trail;
class Bicycle;
#include<iostream>
#include "Ticket.h"
#include "Trail.h"
class Rider{
	friend class Trailhead;
public:
	double skill_lvl;
	double endurance;
	Bicycle *whip;
	Ticket pass;
	Rider(double skill, double enduro){
		this->skill_lvl = skill;
		this->endurance = enduro;
	}
	virtual Trail choice(std::set<Trail*> trails) = 0;
};

#endif