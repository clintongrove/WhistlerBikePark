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
	int arrival_time;
	int departure_time;
	Rider(double skill, double enduro){
		this->skill_lvl = skill;
		this->endurance = enduro;
	}
	virtual Trail* choice(std::set<Trail*> trails) = 0;
	virtual double run(Trail*t) = 0;
};

#endif