#ifndef GOLD_H
#define GOLD_H 

#include <string>
#include "event.h"

using namespace std;

class Gold : public Event
{
private:

public:
	Gold();
	~Gold();
	string get_event_name();

	void percept() const;
    void encounter();
	
};

#endif