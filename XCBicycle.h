#ifndef XCBICYCLE_H_
#define XCBICYCLE_H_
#include <time.h>
#include "Bicycle.h"
class XCBicycle : public Bicycle{
public:
	XCBicycle(){ srand(time(NULL)); }
	bool mechanical(){ return rand() % 1; }//@return bool random mechanical error probability
};

#endif