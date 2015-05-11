#ifndef BICYCLE_H_
#define BICYCLE_H_
class Bicycle{
	friend class Rider;
public:
	Bicycle(){}
	virtual bool mechanical() = 0;
	//~Bicycle(){ delete this; }
};

#endif