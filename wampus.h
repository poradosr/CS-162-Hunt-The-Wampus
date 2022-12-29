#ifndef WAMPUS_H
#define WAMPUS_H 

#include <string>
#include "event.h"

using namespace std;

class Wampus : public Event
{
private:
///
public:
	Wampus();
	~Wampus();
    string get_event_name();

	void percept() const;
    void encounter();
    void shuffle_wampus();
    bool wampus_dead();
	
};

#endif