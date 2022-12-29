#ifndef EVENT_H
#define EVENT_H 

#include <string>

using namespace std;

class Event
{
protected:
	string event_name;
	int x_coordinate;
	int y_coordinate;

public:

	Event();
	Event(string name);
	virtual ~Event();
	string get_event_name();
	int get_x_coordinate();
	int get_y_coordinate();
	void set_x_coordinate(int);
	void set_y_coordinate(int);

	virtual void percept() const = 0;
    virtual void encounter();
	
};
#endif