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
#include "IO.h" 
#include "RiderGenerator.h" 
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
	//int total_time = weeks * 60 * 24 * 7;
	int total_time = 1000;
	IO io; 
	RiderGenerator *riderGen; 
	bool again = true;
public:
	Simulator(){
		Trailhead *Base = new Trailhead();
		Trailhead *Base1 = new Trailhead();
		/*Trailhead *Base2 = new Trailhead();*/

		std::set<Trail*> set1;
		std::set<Trail*>::iterator it = set1.begin();
		Trail *BlackAdder = new EasyTrail(Base1, Base,6.0, 3.0);
		Trail *DaimondBlack = new MedTrail(Base1, Base, 7.0, 4.0);
		Trail *CottonMouth = new HardTrail(Base1, Base, 8.0, 5.0);
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
	void menu(){
		while (again)
		{
			std::string resp = io.print_menu();

			if (resp == "1" || resp == "run simulation" || resp == "Run Simulation")
			{
				io.clear_cmd();
				// I think this will handles any user input for the percentages so that they all add to 1. if they don't then 
				//   my probability calculations are inaccurate. 
				while (again)
				{
					try
					{
						io.get_data();
						again = false;
					}
					catch (std::invalid_argument exp)
					{
						io.clear_cmd();
						cout << exp.what() << "Please try again.\n" << std::endl;
						//io->get_data();
					}
					catch (...)
					{
						cout << "Please try again.\n" << std::endl;
						io.clear_cmd();
					}
				}

				again = true;

				std::vector<std::string> names = io.input_data_from_file();
				riderGen = new RiderGenerator(names, io.get_pbeginner(), io.get_pintermediate(), io.get_padvanced());

				run_simulation();
			}
			else if (resp == "2" || resp == "search" || resp == "Search")
			{
				io.clear_cmd();
				if (riderGen == NULL)
				{
					cout << "The Simulation has not been run.\n" << std::endl;
				}
				else
				{
					std::string s = io.search_name();
					riderGen->search(s);
				}
			}
			else if (resp == "4" || resp == "exit" || resp == "Exit")
			{
				again = false;
			}
			else if (resp == "3" || resp == "output data" || resp == "Output Data")
			{
				io.clear_cmd();
				if (riderGen == NULL)
				{
					cout << "The Simulation has not been run.\n" << std::endl;
				}
				else
				{
					process_data();
				}

			}
			else if (resp == "5" || resp == "print" || resp == "Print")
			{
				io.clear_cmd();
				if (riderGen == NULL)
				{
					cout << "The Simulation has not been run.\n" << std::endl;
				}
				else
				{
					std::vector<string> names = riderGen->get_names();

					for (int i = 0; i < names.size(); i++)
						std::cout << names[i] << std::endl;

					std::cout << std::endl;
				}
			}
			else
			{
				io.clear_cmd();
				std::cout << "Unknown command. Try again.\n" << std::endl;
			}
		}
	}

	/**
		Simulator Deconstructor
		Handles memory 
	*/
	~Simulator() 
	{
		if (riderGen == NULL)
			delete riderGen;
		

	}

	void run_simulation(){
		for (clock = 0; clock < total_time; ++clock){
			random_arrival(clock);
			for (int i = 1; i < heads; i++){
				Trailheads[i]->update(clock);
			}
			for (int i = 0; i < lifts; i++){
				Chairlifts[i]->update(clock);
			}


		}
		//io.clear_cmd();
		std::cout << "\n----------Simulation Done----------\n" << std::endl;

	}

	void random_arrival(int clock)
	{
		double d = riderGen->next_double();
		if (d < io.get_arrival_rate())
		{
			Trailheads[0]->lift->the_queue.push(riderGen->createRider(clock));

		}
	}

	void process_data(){
		std::vector<int> Trailhead_num_served;
		std::vector<int> Trailhead_total_wait;
		std::vector<int> Chairlift_num_served;
		std::vector<int> Chairlift_total_wait;
		std::vector<int> ticket_stats;

		ticket_stats = riderGen->get_ticket_stats();
		
		for (int i = 1; i < heads; i++){
			Trailhead_num_served.push_back(Trailheads[i]->num_served); 
			Trailhead_total_wait.push_back(Trailheads[i]->total_wait);
		}
		for (int i = 1; i < lifts; i++){
			Chairlift_num_served.push_back(Chairlifts[i]->num_served);
			Chairlift_total_wait.push_back(Chairlifts[i]->total_wait);
		}


		io.output_data_to_file(Trailhead_num_served, Trailhead_total_wait, Chairlift_num_served, Chairlift_total_wait, ticket_stats);
	}




};

#endif