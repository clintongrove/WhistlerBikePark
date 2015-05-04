#ifndef SIMULATOR_H_
#define SIMULATOR_H_

#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include <ios>
#include <vector>
#include "Trailhead.h"
#include "ChairLift.h"

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
			
			//update Trail line
			//update chair line
			//

		}

	}






};

#endif