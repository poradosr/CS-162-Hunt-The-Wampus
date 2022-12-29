#include <string>
#include <vector>
#include <iostream>
#include "room.h"

using namespace std;

/*********************************************************************
** Function: Room()
** Description: constructs a roomn with an event and player pointer
** Parameters: None
** Pre-Conditions: player and event were constructed
** Post-Conditions: Must be deconstructed at the end of the game
*********************************************************************/
Room::Room() {
    this->event_ptr = NULL;
    this->player_ptr = NULL;
}

/*********************************************************************
** Function: ~Room()
** Description: Room destructor. Will be called at the end of the game at compile time
** Parameters: None
** Pre-Conditions: Room was constructed
** Post-Conditions: All memory was freed
*********************************************************************/
Room::~Room() {
    delete this->event_ptr;
    this->event_ptr = NULL;

    delete this->player_ptr;
    this->player_ptr = NULL;
}

/*********************************************************************
** Function: get_event_ptr()
** Description: gets the event pointer located in the room object
** Parameters: None
** Pre-Conditions: event pointer was initialized and populated
** Post-Conditions: None
*********************************************************************/
Event* Room::get_event_ptr() {
    return this->event_ptr;
}

/*********************************************************************
** Function: get_player_ptr()
** Description: gets the player pointer located in the room object
** Parameters: None
** Pre-Conditions: player pointer was initialized and populated
** Post-Conditions: None
*********************************************************************/
Player* Room::get_player_ptr() {
    return this->player_ptr;
}

/*********************************************************************
** Function: set_event_ptr(Event*)
** Description: sets the event pointer located in the room object
** Parameters: Event* adventurer
** Pre-Conditions: event pointer was initialized
** Post-Conditions: None
*********************************************************************/
void Room::set_event_ptr(Event* new_event) {
    this->event_ptr = new_event;
}

/*********************************************************************
** Function: set_player_ptr(Player*)
** Description: sets the player pointer located in the room object
** Parameters: Player* adventurer
** Pre-Conditions: player pointer was initialized
** Post-Conditions: None
*********************************************************************/
void Room::set_player_ptr(Player* adventurer) {
    this->player_ptr = adventurer;
}

