#ifndef TICKET_H_
#define TICKET_H_
#include <map>
class Trailhead;
class Trail;
class ChairLift;
class Ticket{
friend class Rider;
private:
	double AvgChairWait = 0;
	double TotChairWait = 0;
	double AvgTrailWait = 0;
	double TotTrailWait = 0;
	std::map<int, Trail*> TrailRecords;
	std::map<int, Trailhead*> TrailheadRecords;
	std::map<int, ChairLift*> ChairLiftRecords;
	
public:
	int boughtat;
	bool valid = true;
	int ticket_no;
	Ticket(){}
	Ticket(int number, int clock){ ticket_no = number; boughtat = clock; }
	void UpdateTrail(int run_time,Trail* trail){
		TrailRecords.insert(std::pair<int,Trail*>(run_time, trail));
	}
	void UpdateTrailhead(int wait_time, Trailhead* trailhead){
		TrailheadRecords.insert(std::pair<int, Trailhead*>(wait_time, trailhead));
	}
	void UpdateChairLift(int wait_time, ChairLift* lift){
		ChairLiftRecords.insert(std::pair<int, ChairLift*>(wait_time, lift));
	}
	void update_ticket(){
		AvgChairWait = avg_wait_chairlifts();
		TotChairWait = tot_wait_chairlifts();
		AvgTrailWait = avg_wait_trailheads();
		TotTrailWait = tot_wait_trailheads();

	}
	void checkvalid(int clock){ if (boughtat + (60 * 5) < clock) valid = false; }
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