#ifndef RIDERGENERATOR_H_
#define RIDERGENERATOR_H_

#include<iostream>
#include <time.h>
#include <set>
#include <map>
#include <iterator>
#include <vector>
#include <string>
#include "Rider.h"
#include "AdvancedRider.h"
#include "BeginnerRider.h"
#include "Trailhead.h"
#include "IntermediateRider.h"
class HardTrail;
class MedTrail;
class EasyTrail;
class BeginnerRider;
class Rider;

class RiderGenerator{
private:
	std::map<std::string, Rider*> riders;
	double pbeginner, padvanced, pintermediate, ticket_no;
public:
	RiderGenerator(){}
	RiderGenerator(double x, double y, double z){
		pbeginner = x;
		pintermediate = y;
		padvanced = z;
		ticket_no = 0;
	}
	void update(){
		Rider *r = new BeginnerRider(3,3,ticket_no);
		ticket_no++;//after rider created to ensure unique ticket no. for each rider
		riders.insert(std::pair<std::string, Rider*>("Greg", r));
		
	}
};

#endif