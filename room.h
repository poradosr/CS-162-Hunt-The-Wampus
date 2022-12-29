#ifndef ROOM_H
#define ROOM_H 

#include <string>
#include <vector>
#include <iostream>
#include "event.h"
#include "player.h"

using namespace std;

class Room
{
private:
    Player* player_ptr;
	Event* event_ptr;

public:

	Room();
	~Room();

    Event* get_event_ptr();
    Player* get_player_ptr();
    void set_event_ptr(Event*);
    void set_player_ptr(Player*);
    void print_rooms();

};
#endif