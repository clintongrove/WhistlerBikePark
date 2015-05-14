#ifndef RIDER_H_
#define RIDER_H_
class Trail;
class Bicycle;
#include<iostream>
#include <string>
#include <set>
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
		this->pass = Ticket(ticket, clock);

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
		pass.update_ticket();
		double d = pass.tot_wait_chairlifts() + pass.tot_wait_trailheads();
		std::string s;
		s.append("Skill Level: " + std::to_string((int)skill_lvl) + "\nEndurance: " + std::to_string((int)endurance)  + "\nTotal Wait Time: "
			+ std::to_string((int)d) + "\nAverage Trailhead Wait Time: " + std::to_string((int) pass.AvgTrailWait) + "\nTotal Trailhead Wait Time: " + std::to_string((int)pass.TotTrailWait) + "\nAverage Chairlift Wait Time: " + std::to_string((int)pass.AvgChairWait) + "\nTotal Chairlift Wait Time: " + std::to_string((int)pass.TotChairWait));
		return s;
	}
};

#endif