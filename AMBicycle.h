#ifndef AMBICYCLE_H_
#define AMBICYCLE_H_
#include <time.h>
#include "Bicycle.h"
class AMBicycle : public Bicycle{
public:
	AMBicycle(){ srand(time(NULL)); }
	bool mechanical(){ return rand() % 1; }
};

#endif