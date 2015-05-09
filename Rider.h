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
	bool onMountaion = false; // This is new
	std::string name; // Do we need this? We have this Rider* in a map with the name as the key
	double skill_lvl;
	double endurance;
	Bicycle *whip;
	Ticket pass;
	int arrival_time;
	int departure_time;
	Rider(double skill, double enduro, int ticket){
		this->skill_lvl = skill;
		this->endurance = enduro;
	}
	~Rider() //This is new
	{
		if (!(whip == NULL))
			delete whip;
	}
	virtual Trail* choice(std::set<Trail*> trails) = 0;
	virtual double run(Trail*t) = 0;

	/*string toString()
	{
	return "Skill Level: " + skill_lvl + "\nEndurance: " + endurance + "\nBicycle: " + whip + "\nTotal Time: "
	+ (departure_time - arrival_time) + "\n";
	}*/
};

#endif