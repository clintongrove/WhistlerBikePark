#ifndef RIDER_H_
#define RIDER_H_
class Trail;
class Bicycle;
#include<iostream>
#include <string>
#include "Ticket.h"
#include "Trail.h"
class Rider{
	friend class Trailhead;
public:
	bool onMountaion = false; 
	double skill_lvl;
	double endurance;
	Bicycle *whip;
	Ticket pass;
	int arrival_time;
	int departure_time;

	Rider(double skill, double enduro, int ticket, int clock){
		this->skill_lvl = skill;
		this->endurance = enduro;
		this->arrival_time = clock;
		this->pass = Ticket(ticket);

	}

	~Rider()
	{
		if (!(whip == NULL))
			delete whip;
	}

	virtual Trail* choice(std::set<Trail*> trails) = 0;
	virtual double run(Trail*t) = 0;

	std::string toString()
	{
		std::string s;
		s.append("Skill Level: " + std::to_string(skill_lvl) + "\nEndurance: " + std::to_string(endurance)  + "\nTotal Time: "
			+ std::to_string(departure_time - arrival_time) + "\n");
		return s;
	}
};

#endif