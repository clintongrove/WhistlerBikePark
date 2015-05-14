#include "ChairLift.h"
#include "Trailhead.h"
#include <iostream>
void ChairLift::pushrider(){
	ChairLift::destination->line(current);//@return void @param none, pushrider() calls Trailhead::line() to push rider. Result of circular dependancy bug fix.
}