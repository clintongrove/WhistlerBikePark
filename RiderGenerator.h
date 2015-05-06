#ifndef BEGINNERRIDER_H_
#define BEGINNERRIDER_H_
class HardTrail;
class MedTrail;
class EasyTrail;
#include<iostream>
#include <time.h>
#include <set>
#include <iterator>
#include <vector>
#include <algorithm>
#include "Rider.h"
#include "AdvancedRider.h"
#include "BeginnerRider.h"
#include "Trailhead.h"
#include "IntermediateRider.h"
class RiderGenerator{
private:
	double pbeginner, padvanced, pintermediate;
public:
	RiderGenerator(){}
	RiderGenerator(double x, double y, double z){
		pbeginner = x;
		pintermediate = y;
		padvanced = z;
	}
	void update(){


	}
};

#endif