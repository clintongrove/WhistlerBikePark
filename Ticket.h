#ifndef TICKET_H_
#define TICKET_H_
#include <iostream>
#include <set>
#include<list>
#include "Rider.h"
class Ticket{
private:
	std::multiset<Rider> records;
	int ticket_no;
public:
	Ticket(){}
	void Update(){}
};

#endif