#ifndef SIMULATOR_H_
#define SIMULATOR_H_

#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
#include <map>
#include "Trailhead.h"
#include "EasyTrail.h"
#include "MedTrail.h"
#include "HardTrail.h"
#include "Rider.h"
#include "ChairLift.h"
class BeginnerRider;
class Trailhead;
class Trail;
class EasyTrail;
class MedTrail;
class HardTrail;


class Simulator{
private:
	int heads;
	int lifts;
	std::vector<Trailhead*> Trailheads;
	std::vector<ChairLift*> Chairlifts;
	int clock;
	int weeks = 2;
	int total_time=weeks*60*24*7;
public:
	Simulator(){
			Trailhead *Base = new Trailhead();
			Trailhead *Base1 = new Trailhead();
			/*Trailhead *Base2 = new Trailhead();*/

			std::set<Trail*> set1;
			std::set<Trail*>::iterator it = set1.begin();
			Trail *BlackAdder = new EasyTrail(Base, Base1, 6.0, 3.0);
			Trail *DaimondBlack = new MedTrail(Base, Base1, 7.0, 4.0);
			Trail *CottonMouth = new HardTrail(Base, Base1, 8.0, 5.0);
			set1.insert(it, BlackAdder);
			set1.insert(it, DaimondBlack);
			set1.insert(it, CottonMouth);

			//std::set<Trail*> set2;
			//std::set<Trail*>::iterator it2 = set2.begin();
			//Trail *WindingSnake = new EasyTrail(Base, Base2, 6.0, 3.0);
			//Trail *CanyonCross = new MedTrail(Base, Base2, 7.0, 4.0);
			//Trail *RopeBridge = new HardTrail(Base, Base2, 8.0, 5.0);
			//set2.insert(it2, WindingSnake);
			//set2.insert(it2, CanyonCross);
			//set2.insert(it2, RopeBridge);


			//std::map<std::string, Trail*> map1;
			//map1.insert(std::pair<std::string,Trail*>("BlackAdder", BlackAdder));
			//map1.insert(std::pair<std::string, Trail*>("DiamondBlack", DaimondBlack));
			//map1.insert(std::pair<std::string, Trail*>("CottonMouth", CottonMouth));

			//std::map<std::string, Trail*> map2;
			//map2.insert(std::pair<std::string, Trail*>("WindingSnake", WindingSnake));
			//map2.insert(std::pair<std::string, Trail*>("CanyonCross", CanyonCross));
			//map2.insert(std::pair<std::string, Trail*>("RopeBridge", RopeBridge));

			ChairLift *lift1 = new ChairLift(Base1, Base);
			Base1->the_trails = set1;
			Base->lift = lift1;
			Chairlifts.push_back(lift1);
			lifts++;
			Trailheads.push_back(Base);
			heads++;
			Trailheads.push_back(Base1);
			heads++;
			
	}
	void enter_data(){

	}
	void run_simulation(){
		for (clock = 0; clock < total_time; ++clock){
			for (int i = 1; i < heads; i++){
				Trailheads[i]->update(clock);
			}
			for (int i = 1; i < lifts; i++){
				Chairlifts[i]->update(clock);
			}


		}

	}
	void process_data(){
		for (int i = 1; i < heads; i++){
			std::cout << Trailheads[i]->num_served << Trailheads[i]->total_wait << std::endl;
		}
		for (int i = 1; i < lifts; i++){
			std::cout << Chairlifts[i]->num_served << Chairlifts[i]->total_wait << std::endl;
		}

	}





};

#endif