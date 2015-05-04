#ifndef BICYCLE_H_
#define BICYCLE_H_
class Bicycle{
	friend class Rider;
private:
	virtual bool mechanical() = 0;
public:
	Bicycle(){}

};

#endif