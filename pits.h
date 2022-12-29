#ifndef PITS_H
#define PITS_H 

#include <string>
#include "event.h"

using namespace std;

class Pits : public Event
{
private:

public:
	Pits();
	~Pits();
	string get_event_name();

	void percept() const;
    void encounter();
	
};

#endif