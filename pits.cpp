#include "pits.h"

#include <iostream>

using namespace std;

/*********************************************************************
** Function: Pits() : Event("P")
** Description: Sets Pits to be inherited from the event class and constructs its specific event name
** Parameters: string name
** Pre-Conditions: None
** Post-Conditions: Must be deconstructed at the end of the game
*********************************************************************/
Pits::Pits() : Event("P") {

}

/*********************************************************************
** Function: ~Pits()
** Description: Pits destructor. Will be called at the end of the game at run time
** Parameters: None
** Pre-Conditions: Pits was constructed
** Post-Conditions: All memory was freed
*********************************************************************/
Pits::~Pits() {

}

/*********************************************************************
** Function: get_event_name()
** Description: gets the name of an event
** Parameters: None
** Pre-Conditions: event name must have been initialized
** Post-Conditions: None
*********************************************************************/
string Pits::get_event_name() {
	return event_name;
}

/*********************************************************************
** Function: percept() const
** Description: Displayes the percept of the pits
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void Pits::percept() const {
	cout << "You feel a breeze" << endl;
}

/*********************************************************************
** Function: encounter()
** Description: an encounter function inherited from the event class
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void Pits::encounter() {

}