#ifndef TICKET_H_
#define TICKET_H_
#include <map>
class Trailhead;
class Trail;
class ChairLift;
class Ticket{
private:
	bool valid = 1;
	std::map<int, Trail*> TrailRecords;
	std::map<int, Trailhead*> TrailheadRecords;
	std::map<int, ChairLift*> ChairLiftRecords;
	int ticket_no;
public:
	Ticket(){}
	void UpdateTrail(int run_time,Trail* trail){
		TrailRecords.insert(std::pair<int,Trail*>(run_time, trail));
	}
	void UpdateTrailhead(int wait_time, Trailhead* trailhead){
		TrailheadRecords.insert(std::pair<int, Trailhead*>(wait_time, trailhead));
	}
	void UpdateChairLift(int wait_time, ChairLift* lift){
		ChairLiftRecords.insert(std::pair<int, ChairLift*>(wait_time, lift));
	}
};

#endif