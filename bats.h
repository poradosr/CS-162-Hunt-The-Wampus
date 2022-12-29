#ifndef BATS_H
#define BATS_H 

#include <string>
#include "event.h"

using namespace std;

class Bats : public Event
{
private:

public:
	Bats();
	~Bats();
	string get_event_name();

	void percept() const;
    void encounter();
	
};

#endif