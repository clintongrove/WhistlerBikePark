#ifndef XCBICYCLE_H_
#define XCBICYCLE_H_
#include <time.h>
#include "Bicycle.h"
class XCBicycle : public Bicycle{
private:
	bool mechanical(){ return rand()%1; }
public:
	XCBicycle(){ srand(time(NULL)); }

};

#endif