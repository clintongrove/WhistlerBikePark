#ifndef _RIDERGENERATOR_h
#define _RIDERGENERATOR_h

#include <iostream>
#include <random> 
#include <set>
#include <map>
#include <iterator>
#include <vector>
#include <string>
#include <time.h>
#include "Rider.h"
#include "AdvancedRider.h"
#include "BeginnerRider.h"
#include "IntermediateRider.h"
/*class HardTrail;
class MedTrail;
class EasyTrail;
class BeginnerRider;
class Rider;*/

using std::string;

class RiderGenerator{
private:
	std::map<string, Rider*> riders;
	std::vector<string> names;
	double pbeginner, padvanced, pintermediate;
	int ticket_no;
	Rider *r = NULL;
public:
	RiderGenerator(){}
	RiderGenerator(std::vector<string> DataVille, double x, double y, double z) : pbeginner(x), pintermediate(y),
		padvanced(x), ticket_no(0), names(DataVille)
	{
		srand(time(NULL));
	}

	~RiderGenerator()
	{
		std::map<string, Rider*>::iterator it = riders.begin();

		while (!(it == riders.end()))
		{
			delete it->second;
		}

		if (r == NULL)
			delete r;
	}



	Rider* createRider(int clock)
	{
		int rider;
		rider = rand() % names.size();
		string random_name = names[rider];

		std::map<string, Rider*>::iterator it = riders.find(random_name);

		while (!(it == riders.end()))
		{
			if (!it->second->onMountaion)
			{
				it->second->onMountaion = true;
				return it->second;
			}
			else
			{
				rider = rand() % names.size();
				random_name = names[rider];
				it = riders.find(random_name);
			}

		}

		double who = ((double)rand() / RAND_MAX); // makes a double between 0 and 1

		if (who <= pbeginner)
		{
			r = new BeginnerRider(get_skill_level("beginner"), get_endurance("beginner"), ticket_no, clock);
			riders.insert(std::pair<string, Rider*>(random_name, r));
			ticket_no++; 
		}
		else if (who <= (pbeginner + pintermediate) && who > pbeginner)
		{
			r = new IntermediateRider(get_skill_level("intermediate"), get_endurance("intermediate"), ticket_no, clock);
			riders.insert(std::pair<string, Rider*>(random_name, r));
			ticket_no++;
		}
		else if (who > (pbeginner + pintermediate))
		{
			r = new AdvancedRider(get_skill_level("advanced"), get_endurance("advanced"), ticket_no, clock);
			riders.insert(std::pair<string, Rider*>(random_name, r));
			ticket_no++;
		}

		//delete r;

		return riders.find(random_name)->second;
	}

	int get_endurance(string rider_type)
	{
		if (rider_type == "beginner")
			return rand() % 3;
		else if (rider_type == "intermediate")
			return rand() % 3 + 4;
		else if (rider_type == "advanced")
			return rand() % 3 + 7;
	}

	int get_skill_level(string rider_type)
	{
		if (rider_type == "beginner")
			return rand() % 3;
		else if (rider_type == "intermediate")
			return rand() % 3 + 4;
		else if (rider_type == "advanced")
			return rand() % 3 + 7;
	}

	std::vector<int> get_ticket_stats()
	{ 
		std::vector<int> vec;
		int BRider_avg_trailhead_wait = 0;
		int BRider_total_trailhead_wait = 0;
		int BRider_avg_chairlift_wait = 0;
		int BRider_total_chairlift_wait = 0;
		int IRider_avg_trailhead_wait = 0;
		int IRider_total_trailhead_wait = 0;
		int IRider_avg_chairlift_wait = 0;
		int IRider_total_chairlift_wait = 0;
		int ARider_avg_trailhead_wait = 0;
		int ARider_total_trailhead_wait = 0;
		int ARider_avg_chairlift_wait = 0;
		int ARider_total_chairlift_wait = 0;
		int Bnum = 0;
		int Inum = 0;
		int Anum = 0;
		for (std::map<string, Rider*>::iterator it = riders.begin(); it != riders.end(); ++it){
			if (typeid(it->second) == typeid(BeginnerRider)){
				BRider_total_chairlift_wait+=it->second->pass.tot_wait_chairlifts();
				BRider_total_trailhead_wait += it->second->pass.tot_wait_trailheads();
				Bnum++;
			}
			if (typeid(it->second) == typeid(IntermediateRider)){
				IRider_total_chairlift_wait += it->second->pass.tot_wait_chairlifts();
				IRider_total_trailhead_wait += it->second->pass.tot_wait_trailheads();
				Inum++;
			}
			if (typeid(it->second) == typeid(AdvancedRider)){
				ARider_total_chairlift_wait += it->second->pass.tot_wait_chairlifts();
				ARider_total_trailhead_wait += it->second->pass.tot_wait_trailheads();
				Anum++;
			}
			vec.push_back(BRider_avg_trailhead_wait = BRider_total_trailhead_wait/Bnum);
			vec.push_back(BRider_avg_chairlift_wait = BRider_total_chairlift_wait / Bnum);
			vec.push_back(IRider_avg_trailhead_wait = IRider_total_trailhead_wait / Inum);
			vec.push_back(IRider_avg_chairlift_wait = IRider_total_chairlift_wait / Inum);
			vec.push_back(ARider_avg_trailhead_wait = ARider_total_trailhead_wait / Anum);
			vec.push_back(ARider_avg_chairlift_wait = ARider_total_chairlift_wait / Anum);
			
		}
		return vec;
	}

	std::vector<string> get_names(){ return names; }

	void search(string name)
	{
		//std::string s = riders.find(name)->second->toString();
		std::map<string, Rider*>::iterator it = riders.find(name);

		if (it == riders.end())
			std::cout << "Don't recognize that name.\n" <<std::endl;
		else
			std::cout << it->second->toString() << std::endl << std::endl;
	}

	double next_double()
	{
		return double(rand()) / RAND_MAX;
	}
};

#endif