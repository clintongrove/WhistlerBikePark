#ifndef DHBICYCLE_H_
#define DHBICYCLE_H_
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Bicycle.h"
class DHBicycle : public Bicycle{
private:
	bool mechanical(){ return rand() % 1; }
public:
	DHBicycle(){}
	DHBicycle(){ srand(time(NULL)); }

};

#endif