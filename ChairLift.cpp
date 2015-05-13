#include "ChairLift.h"
#include "Trailhead.h"
#include <iostream>
void ChairLift::pushrider(){
	ChairLift::destination->Trailhead::line(current);
	std::cout << "RIDER PSUHED!!!" << std::endl;
}