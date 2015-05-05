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
using namespace std;

int main(){
	int clock;

	Trailhead *Base = new Trailhead();
	Trailhead *Base1 = new Trailhead();
	Trailhead *Base2 = new Trailhead();

	std::set<Trail*> set1;
	std::set<Trail*>::iterator it = set1.begin();
	Trail *BlackAdder = new EasyTrail(Base, Base1, 6.0, 3.0);
	Trail *DaimondBlack = new MedTrail(Base, Base1, 7.0, 4.0);
	Trail *CottonMouth = new HardTrail(Base, Base1, 8.0, 5.0);
	set1.insert(it, BlackAdder);
	set1.insert(it, DaimondBlack);
	set1.insert(it, CottonMouth);

	std::set<Trail*> set2;
	std::set<Trail*>::iterator it2 = set2.begin();
	Trail *WindingSnake = new EasyTrail(Base, Base2, 6.0, 3.0);
	Trail *CanyonCross = new MedTrail(Base, Base2, 7.0, 4.0);
	Trail *RopeBridge = new HardTrail(Base, Base2, 8.0, 5.0);
	set2.insert(it2, WindingSnake);
	set2.insert(it2, CanyonCross);
	set2.insert(it2, RopeBridge);


	std::map<string, Trail*> map1;
	map1.insert(make_pair("BlackAdder", BlackAdder));
	map1.insert(make_pair("DiamondBlack", DaimondBlack));
	map1.insert(make_pair("CottonMouth", CottonMouth));

	std::map<string, Trail*> map2;
	map2.insert(make_pair("WindingSnake", WindingSnake));
	map2.insert(make_pair("CanyonCross", CanyonCross));
	map2.insert(make_pair("RopeBridge", RopeBridge));



	ChairLift *lift1 = new ChairLift(Base1, Base);
	Base1->the_trails = set1;
	Base->lift = lift1;
	

	


}