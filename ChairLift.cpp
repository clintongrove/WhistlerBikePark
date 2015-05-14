#include "ChairLift.h"
#include "Trailhead.h"
#include <iostream>
void ChairLift::pushrider(){//@return void @param none, pushrider() calls Trailhead::line() to push rider. Result of circular dependancy bug fix.
	ChairLift::destination->line(current);
}