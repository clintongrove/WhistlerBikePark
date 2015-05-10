#ifndef _RIDERGENERATOR_h
#define _RIDERGENERATOR_h

#include <iostream>
#include <random> 
#include <set>
#include <map>
#include <iterator>
#include <vector>
#include <string>
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
	}



	Rider* createRider()
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
		Rider *r;

		if (who <= pbeginner)
		{
			r = new BeginnerRider(get_skill_level("beginner"), get_endurance("beginner"), ticket_no);
			riders.insert(std::pair<string, Rider*>(random_name, r));
			ticket_no++; 
		}
		else if (who <= (pbeginner + pintermediate) && who > pbeginner)
		{
			r = new IntermediateRider(get_skill_level("intermediate"), get_endurance("intermediate"), ticket_no);
			riders.insert(std::pair<string, Rider*>(random_name, r));
			ticket_no++;
		}
		else if (who > (pbeginner + pintermediate))
		{
			r = new AdvancedRider(get_skill_level("advanced"), get_endurance("advanced"), ticket_no);
			riders.insert(std::pair<string, Rider*>(random_name, r));
			ticket_no++;
		}

		delete r;

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

	void search(string name)
	{
		std::cout << riders.find(name)->second->toString() << std::endl;
	}
};

#endif