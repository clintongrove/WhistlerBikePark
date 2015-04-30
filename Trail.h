#ifndef TRAIL_H_
#define TRAIL_H_
class Trail{

public:
	Trail(){}
	bool inuse;
	double difficulty;
	double distance;
	Trailhead *destination;
	Trailhead *origin;
};

#endif