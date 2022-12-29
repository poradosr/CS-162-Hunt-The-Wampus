#include "bats.h"

#include <iostream>

using namespace std;

/*********************************************************************
** Function: Bats() : Event("B")
** Description: Sets Bats to be inherited from the event class and constructs its specific event name
** Parameters: string name
** Pre-Conditions: None
** Post-Conditions: Must be deconstructed at the end of the game
*********************************************************************/
Bats::Bats() : Event("B") {

}

/*********************************************************************
** Function: ~Bats()
** Description: Bats destructor. Will be called at the end of the game at run time
** Parameters: None
** Pre-Conditions: Bats was constructed
** Post-Conditions: All memory was freed
*********************************************************************/
Bats::~Bats() {

}

/*********************************************************************
** Function: get_event_name()
** Description: gets the name of an event
** Parameters: None
** Pre-Conditions: event name must have been initialized
** Post-Conditions: None
*********************************************************************/
string Bats::get_event_name() {
	return event_name;
}

/*********************************************************************
** Function: percept() const
** Description: Displayes the percept of the bats
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void Bats::percept() const {
	cout << "You hear wings flapping" << endl;
}

/*********************************************************************
** Function: encounter()
** Description: an encounter function inherited from the event class
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void Bats::encounter() {

}