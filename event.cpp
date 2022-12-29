#include <string>
#include <iostream>
#include "event.h"

using namespace std;

/*********************************************************************
** Function: Event()
** Description: Constructs an event that can occur in a room of the cave
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Must be deconstructed at the end of the game
*********************************************************************/
Event::Event() {
    this->event_name = "some event";
}

/*********************************************************************
** Function: Event(string)
** Description: Event parametized constructor. Creates a game with member variable name
** Parameters: string name
** Pre-Conditions: None
** Post-Conditions: Must be deconstructed at the end of the game
*********************************************************************/
Event::Event(string name) {
    this->event_name = name;
    this->x_coordinate = -1;
    this->y_coordinate = -1;
}

/*********************************************************************
** Function: get_event_name()
** Description: gets the name of an event
** Parameters: None
** Pre-Conditions: event name must have been initialized
** Post-Conditions: None
*********************************************************************/
string Event::get_event_name() {
    return this->event_name;
}

/*********************************************************************
** Function: get_x_coordinate()
** Description: gets the x-coordinate of an event
** Parameters: None
** Pre-Conditions: event x-coordinate must have been initialized
** Post-Conditions: None
*********************************************************************/
int Event::get_x_coordinate() {
    return this->x_coordinate;
}

/*********************************************************************
** Function: get_y_coordinate()
** Description: gets the y-coordinate of an event
** Parameters: None
** Pre-Conditions: event y-coordinate must have been initialized
** Post-Conditions: None
*********************************************************************/
int Event::get_y_coordinate() {
    return this->y_coordinate;
}

/*********************************************************************
** Function: set_x_coordinate(int)
** Description: sets the x-coordinate of an event to the variable input
** Parameters: int x
** Pre-Conditions: x-coordinate is a member variable of the class
** Post-Conditions: x-coordinate is initialized
*********************************************************************/
void Event::set_x_coordinate(int x) {
    this->x_coordinate = x;
}

/*********************************************************************
** Function: set_y_coordinate(int)
** Description: sets the y-coordinate of an event to the variable input
** Parameters: int y
** Pre-Conditions: y-coordinate is a member variable of the class
** Post-Conditions: y-coordinate is initialized
*********************************************************************/
void Event::set_y_coordinate(int y) {
    this->y_coordinate = y;
}

/*********************************************************************
** Function: ~Event()
** Description: Event destructor. Will be called at the end of the game at run time
** Parameters: None
** Pre-Conditions: Event was constructed
** Post-Conditions: All memory was freed
*********************************************************************/
Event::~Event() {

}

/*********************************************************************
** Function: percept() const
** Description: pure abstract function that will be used in child classes
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void Event::percept() const {

}

/*********************************************************************
** Function: encounter()
** Description: pure abstract function that will be used in child classes
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void Event::encounter() {

}