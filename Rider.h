#ifndef RIDER_H_
#define RIDER_H_
#include <iostream>

class Rider{
	friend class Trailhead;
private:
	double skill_lvl;
	double endurance;
	
public:
	Rider(){}
	Rider(double skill, double enduro){
		skill_lvl = skill;
		endurance = enduro;}
	Ticket pass;
	virtual void choice() = 0;
};

#endif