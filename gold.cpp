#include "gold.h"

#include <iostream>

using namespace std;

/*********************************************************************
** Function: Gold() : Event("G")
** Description: Sets Gold to be inherited from the event class and constructs its specific event name
** Parameters: string name
** Pre-Conditions: None
** Post-Conditions: Must be deconstructed at the end of the game
*********************************************************************/
Gold::Gold() : Event("G") {

}

/*********************************************************************
** Function: ~Gold()
** Description: Gold destructor. Will be called at the end of the game at run time
** Parameters: None
** Pre-Conditions: Pits was constructed
** Post-Conditions: All memory was freed
*********************************************************************/
Gold::~Gold() {

}

/*********************************************************************
** Function: get_event_name()
** Description: gets the name of an event
** Parameters: None
** Pre-Conditions: event name must have been initialized
** Post-Conditions: None
*********************************************************************/
string Gold::get_event_name() {
	return event_name;
}

/*********************************************************************
** Function: percept() const
** Description: Displayes the percept of the gold
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void Gold::percept() const {
	cout << "You see a glimmer nearby" << endl;
}

/*********************************************************************
** Function: encounter()
** Description: an encounter function inherited from the event class
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void Gold::encounter() {

}