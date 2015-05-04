#ifndef AMBICYCLE_H_
#define AMBICYCLE_H_
#include <time.h>
#include "Bicycle.h"
class AMBicycle : public Bicycle{
private:
	bool mechanical(){ return rand() % 1; }
public:
	AMBicycle(){ srand(time(NULL)); }

};

#endif