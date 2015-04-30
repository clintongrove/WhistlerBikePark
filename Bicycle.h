#ifndef BICYCLE_H_
#define BICYCLE_H_
#include <iostream>

class Bicycle : public Bicycle{
	friend class Rider;
private:
	virtual bool mechanical() = 0;
public:
	Bicycle(){}

};

#endif