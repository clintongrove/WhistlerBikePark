#ifndef TICKET_H_
#define TICKET_H_
#include <map>
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
		TrailRecords.insert(make_pair(run_time, trail));
	}
	void UpdateTrailhead(int wait_time, Trailhead* trailhead){
		TrailheadRecords.insert(make_pair(wait_time, trailhead));
	}
	void UpdateChairLift(int wait_time, ChairLift* lift){
		ChairLiftRecords.insert(make_pair(wait_time, lift));
	}
};

#endif