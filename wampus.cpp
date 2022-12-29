#include "wampus.h"

#include <iostream>

using namespace std;

/*********************************************************************
** Function: Wampus() : Event("W")
** Description: Sets Wampus to be inherited from the event class and constructs its specific event name
** Parameters: string name
** Pre-Conditions: None
** Post-Conditions: Must be deconstructed at the end of the game
*********************************************************************/
Wampus::Wampus() : Event("W") {

}
/*********************************************************************
** Function: ~Wampus()
** Description: Wampus destructor. Will be called at the end of the game at run time
** Parameters: None
** Pre-Conditions: Wampus was constructed
** Post-Conditions: All memory was freed
*********************************************************************/
Wampus::~Wampus() {

}

/*********************************************************************
** Function: get_event_name()
** Description: gets the name of an event
** Parameters: None
** Pre-Conditions: event name must have been initialized
** Post-Conditions: None
*********************************************************************/
string Wampus::get_event_name() {
	return event_name;
}

/*********************************************************************
** Function: percept() const
** Description: Displayes the percept of the wampus
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void Wampus::percept() const {
    // if player is 1 room near, display:
	cout << "You smell a terrible stench" << endl;
}

/*********************************************************************
** Function: encounter()
** Description: an encounter function inherited from the event class
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void Wampus::encounter() {

}