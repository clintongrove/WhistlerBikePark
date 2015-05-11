#ifndef TICKET_H_
#define TICKET_H_
#include <map>
class Trailhead;
class Trail;
class ChairLift;
class Ticket{
private:
	
	std::map<int, Trail*> TrailRecords;
	std::map<int, Trailhead*> TrailheadRecords;
	std::map<int, ChairLift*> ChairLiftRecords;
	
public:
	bool valid = 1;
	int ticket_no;
	Ticket(){}
	Ticket(int number){ ticket_no = number; }
	void UpdateTrail(int run_time,Trail* trail){
		TrailRecords.insert(std::pair<int,Trail*>(run_time, trail));
	}
	void UpdateTrailhead(int wait_time, Trailhead* trailhead){
		TrailheadRecords.insert(std::pair<int, Trailhead*>(wait_time, trailhead));
	}
	void UpdateChairLift(int wait_time, ChairLift* lift){
		ChairLiftRecords.insert(std::pair<int, ChairLift*>(wait_time, lift));
	}

	double avg_wait_trailheads()
	{
		int tot = 0;
		int num = 0;
		std::map<int, Trailhead*>::iterator it = TrailheadRecords.begin();

		for (it; it != TrailheadRecords.end(); it++){
			tot += it->first;
			num++;
		}
		return tot / num;
	}
	double tot_wait_trailheads()
	{
		int tot = 0;
		std::map<int, Trailhead*>::iterator it = TrailheadRecords.begin();

		for (it; it != TrailheadRecords.end(); it++){
			tot += it->first;
		}
		return tot;
	}
	double avg_wait_chairlifts()
	{
		int tot = 0;
		int num = 0;
		std::map<int, ChairLift*>::iterator it = ChairLiftRecords.begin();

		for (it; it != ChairLiftRecords.end(); it++){
			tot += it->first;
			num++;
		}
		return tot/num;
	}
	double tot_wait_chairlifts()
	{
		int tot = 0;
		std::map<int, ChairLift*>::iterator it = ChairLiftRecords.begin();

		for (it; it != ChairLiftRecords.end(); it++){
			tot += it->first;
		}
		return tot;
	}
};

#endif