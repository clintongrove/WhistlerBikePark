#ifndef DHBICYCLE_H_
#define DHBICYCLE_H_
#include <time.h>
#include "Bicycle.h"
class DHBicycle : public Bicycle{
public:
	DHBicycle(){ srand(time(NULL)); }
	bool mechanical(){ return rand() % 1; }
};

#endif