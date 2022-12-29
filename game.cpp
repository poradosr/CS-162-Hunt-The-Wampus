#include "game.h"
#include <iomanip> 
#include <iostream>

using namespace std;

/*********************************************************************
** Function: Game() 
** Description: Game constructor. Creates a game object
** Parameters: None
** Pre-Conditions: Game has been initialized and populated 
** Post-Conditions: must include other classes to allow access
*********************************************************************/
Game::Game() {

}

/*********************************************************************
** Function: ~Game() 
** Description: Game deconstructor. Is called when program ends
** Parameters: None
** Pre-Conditions: Game has been initialized
** Post-Conditions: Must check for memory leaks 
*********************************************************************/
Game::~Game() {
}

/*********************************************************************
** Function: get_size()
** Description: Prints the size of a length of the grid
** Parameters: None
** Pre-Conditions: The user inputted their wanted cave size and the corresponding member variable was initialized.
** Post-Conditions: Cave is a matrix of this size
*********************************************************************/
int Game::get_size() {
    return size;
}

string Game::player_symbol() {
    return "*";
}

// cave Game::get_cave(int row, int col) {
//     return this->cave[col][row];
// }

/*********************************************************************
** Function: populate_cave()
** Description: Populates the cave with 6 events in random locations
** Parameters: None
** Pre-Conditions: The user inputted their wanted cave size and the event class and has been properly set up with polymorphism
** Post-Conditions: Each cave has an event pointer that either points to an event or to NULL
*********************************************************************/
void Game::populate_cave() {
    Event* bat1 = new Bats();
    generate_room(bat1);
    Event* bat2 = new Bats();
    generate_room(bat2);
    Event* pit1 = new Pits();
    generate_room(pit1);
    Event* pit2 = new Pits();
    generate_room(pit2);
    Event* wampus = new Wampus();
    generate_room(wampus);
    Event* gold = new Gold();
    generate_room(gold);
}
 
/*********************************************************************
** Function: populate_empty()
** Description: Initializes and populates the cave with temporary vectors
** Parameters: None
** Pre-Conditions: The user inputted their wanted cave size and the room class has been created
** Post-Conditions: The cave must be populated
*********************************************************************/
void Game::populate_empty() {
    for (int i = 0; i < this->size; i++) {
        vector <Room> temp_vec;
        cave.push_back(temp_vec);
        for (int j = 0; j < this->size; j++) {
            Room temp_room;
            cave[i].push_back(temp_room);
        }
    }    
}

/*********************************************************************
** Function: generate_room(Event*)
** Description: generates a random room to place an event in the cave
** Parameters: Event* new_event
** Pre-Conditions: The user inputted their wanted cave size and the room class as well as the event classes have been created
** Post-Conditions: No two events can share the same room
*********************************************************************/
void Game::generate_room(Event* new_event) {
    int row;
    int col;

    row = rand() % this->size;
    col = rand() % this->size;

    while (cave[row][col].get_event_ptr() != NULL) {
        row = rand() % this->size;
        col = rand() % this->size;
    }

    new_event->set_x_coordinate(col);
    new_event->set_y_coordinate(row);
    cave[row][col].set_event_ptr(new_event);
}

/*********************************************************************
** Function: print_cave()
** Description: Prints the layout of the rooms of the cave.
** Parameters: None
** Pre-Conditions: The member variables of the room class have been initialized and populated.
** Post-Conditions: Prints out the debug mode version of the game
*********************************************************************/
void Game::print_cave() {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            if (cave[i][j].get_event_ptr() == NULL && cave[i][j].get_player_ptr() == NULL) {
                cout << "|     |";
            }
            else if (cave[i][j].get_event_ptr() == NULL && cave[i][j].get_player_ptr() != NULL) {
            cout << "|  " << player_symbol() << "  |";
            }
            else if (cave[i][j].get_event_ptr() != NULL && cave[i][j].get_player_ptr() == NULL) {
            cout << "|  " << cave[i][j].get_event_ptr()->get_event_name() << "  |";
            }

        }    
        cout << endl;
    }
}

/*********************************************************************
** Function: print_cave_non_debug()
** Description: Prints the layout of the rooms of the cave while hiding the events
** Parameters: None
** Pre-Conditions: The member variables of the room class have been initialized and populated.
** Post-Conditions: Prints out the non-debug mode version of the game
*********************************************************************/
void Game::print_cave_non_debug() {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            if (cave[i][j].get_event_ptr() == NULL && cave[i][j].get_player_ptr() == NULL) {
                cout << "|     |";
            }
            else if (cave[i][j].get_event_ptr() == NULL && cave[i][j].get_player_ptr() != NULL) {
            cout << "|  " << player_symbol() << "  |";
            }
            else if (cave[i][j].get_event_ptr() != NULL && cave[i][j].get_player_ptr() == NULL) {
            cout << "|     |";
            }

        }    
        cout << endl;
    }
}

/*********************************************************************
** Function: debug_mode()
** Description: returns true is the user wants to play in debug mode and false otherwise
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
bool Game::debug_mode() {
    char debug_mode;
    cout << "Would you like to play the game in debug mode? (y/n)" << endl;
    cin >> debug_mode;
    if (debug_mode == 'y') {
        return true;
    }
    else if (debug_mode == 'n') {
        return false;
    }
}

/*********************************************************************
** Function: start_game()
** Description: Asks the user ehat grid size thry would like to play in.
** Parameters: None
** Pre-Conditions: The grid size must be large enough to hold all events
** Post-Conditions: The cave is created according to the inputted size
*********************************************************************/
void Game::start_game() {
    int grid_size;
    cout << "Please enter an integer greater than 3 for the game grid size: ";
    cin >> grid_size;
    while (grid_size < 4) {
        cout << "Invalid input... Try again: ";
        cin >> grid_size;
        cout << endl;
    }
    this->size = grid_size;
    cout << endl;
}

/*********************************************************************
** Function: coordinates_player()
** Description: Generates initial coordinates for the player pointer and sets them to the corresponding member variables
** Parameters: None
** Pre-Conditions: Player struct has been initialized and a pointer has been added as a member variable to the Game class
** Post-Conditions: The player cannot land on same coordinates as any event
*********************************************************************/
void Game::coordinates_player() {
    int row;
    int col;

    row = rand() % this->size; // generate random y-coordinate
    col = rand() % this->size; // generate random x-coordinate


    // Error handling: checks that initial placement of player is not in room with events
    while (cave[row][col].get_event_ptr() != NULL) {
        row = rand() % this->size; // generate random y-coordinate
        col = rand() % this->size; // generate random x-coordinate
    }

    this->p1 = new Player();
    cave[row][col].set_player_ptr(p1);
    p1->initial_x_coord = col; // set player's initial x-coordinate
    p1->initial_y_coord = row; // set player's initial y-coordinate
    p1->current_x_coord = col; // set player's current x-coordinate
    p1->current_y_coord = row; // set player's current y-coordinate
}

/*********************************************************************
** Function: shift_player()
** Description: Generates new coordinates for the player pointer and sets them to the corresponding member variables
** Parameters: None
** Pre-Conditions: Player struct has been initialized and a pointer has been added as a member variable to the Game class
** Post-Conditions: The player can land on any event 
*********************************************************************/
void Game::shift_player() {
    int row;
    int col;

    row = rand() % this->size; // generate random y-coordinate
    col = rand() % this->size; // generate random x-coordinate

    cave[row][col].set_player_ptr(p1);
    p1->current_x_coord = col; // set player's current x-coordinate
    p1->current_y_coord = row; // set player's current y-coordinate
}

/*********************************************************************
** Function: move_player()
** Description: Moves the player 1 room according to user's input
** Parameters: None
** Pre-Conditions: Player struct has been initialized and a pointer has been added as a member variable to the Game class
** Post-Conditions: The player pointer from a previous room was set to NULL
*********************************************************************/
void Game::move_player() {
    char direction;
    cout << "Enter a direction to move (w, a, s, d): ";
    cin >> direction;

        if (direction == 'w' && (in_bounds(p1->current_y_coord - 1, p1->current_x_coord) == true)) {
            cave[p1->current_y_coord - 1][p1->current_x_coord].set_player_ptr(cave[p1->current_y_coord ][p1->current_x_coord].get_player_ptr());
            cave[p1->current_y_coord ][p1->current_x_coord].set_player_ptr(NULL);
            p1->current_y_coord --;
        }
        else if (direction == 'a' && (in_bounds(p1->current_y_coord, p1->current_x_coord - 1) == true)) {
            cave[p1->current_y_coord][p1->current_x_coord - 1].set_player_ptr(cave[p1->current_y_coord ][p1->current_x_coord].get_player_ptr());
            cave[p1->current_y_coord ][p1->current_x_coord].set_player_ptr(NULL);
            p1->current_x_coord --;
        }
        else if (direction == 's' && (in_bounds(p1->current_y_coord + 1, p1->current_x_coord) == true)) {
            cave[p1->current_y_coord + 1][p1->current_x_coord].set_player_ptr(cave[p1->current_y_coord ][p1->current_x_coord].get_player_ptr());
            cave[p1->current_y_coord ][p1->current_x_coord].set_player_ptr(NULL);
            p1->current_y_coord ++;
        }
        else if (direction == 'd' && (in_bounds(p1->current_y_coord, p1->current_x_coord + 1) == true)) {
            cave[p1->current_y_coord][p1->current_x_coord + 1].set_player_ptr(cave[p1->current_y_coord ][p1->current_x_coord].get_player_ptr());
            cave[p1->current_y_coord ][p1->current_x_coord].set_player_ptr(NULL);
            p1->current_x_coord ++;

        }
    else  {
        cout << "Cannot move in that direction. Out of bounds" << endl;
    }
}

/*********************************************************************
** Function: print_percepts()
** Description: Prints a percept if the player is located one room next to an event
** Parameters: None
** Pre-Conditions: Polymorphism was applied in event class
** Post-Conditions: None
*********************************************************************/
void Game::print_percepts() { 
    if (in_bounds(p1->current_y_coord, p1->current_x_coord - 1) && cave[p1->current_y_coord][p1->current_x_coord - 1].get_event_ptr() != NULL) { //looking up 
        cave[p1->current_y_coord][p1->current_x_coord - 1].get_event_ptr()->percept();
    }
    if (in_bounds(p1->current_y_coord, p1->current_x_coord + 1) && cave[p1->current_y_coord][p1->current_x_coord + 1].get_event_ptr() != NULL) { //looking down 
        cave[p1->current_y_coord][p1->current_x_coord + 1].get_event_ptr()->percept();
    }
    if (in_bounds(p1->current_y_coord - 1, p1->current_x_coord) && cave[p1->current_y_coord - 1][p1->current_x_coord].get_event_ptr() != NULL) { //looking west
        cave[p1->current_y_coord - 1][p1->current_x_coord].get_event_ptr()->percept();
    }
    if (in_bounds(p1->current_y_coord + 1, p1->current_x_coord) && cave[p1->current_y_coord + 1][p1->current_x_coord].get_event_ptr() != NULL) { //looking east
        cave[p1->current_y_coord + 1][p1->current_x_coord].get_event_ptr()->percept();
    }
}

/*********************************************************************
** Function: run_game()
** Description: runs the game as long as the player has not died
** Parameters: None
** Pre-Conditions: In_bounds function makes sure all memory accessed is valid
** Post-Conditions: Ends the game once member variable game_over is true
*********************************************************************/
void Game::run_game() {
    while (game_over == false) {
        get_player_action();
        check_event();
        if (game_over == true) {
            break;
        }
        print_cave();
        print_percepts();
        check_if_won();
    }
    play_again();
}

/*********************************************************************
** Function: run_game()
** Description: runs the game as long as the player has not died while hiding the events from player
** Parameters: None
** Pre-Conditions: In_bounds function makes sure all memory accessed is valid
** Post-Conditions: Ends the game once member variable game_over is true
*********************************************************************/
void Game::run_game_non_debug() {
    while (game_over == false) {
        get_player_action();
        check_event();
        if (game_over == true) {
            break;
        }
        print_cave_non_debug();
        print_percepts();
        check_if_won();
    }
    play_again();
}

/*********************************************************************
** Function: get_player_action()
** Description: moves or shoots an arrow according to player input
** Parameters: None
** Pre-Conditions: In_bounds function makes sure all memory accessed is valid
** Post-Conditions: None
*********************************************************************/
void Game::get_player_action() {
    int player_action;
	cout << "Would you like to move (1) or fire an arrow (2)? ";
	cin >> player_action;
    if (player_action == 1) {
        move_player();
    }
    else if (player_action == 2) {
        shoot_arrow();
        adjust_arrows();
    }
	while (player_action != 1 && player_action != 2){
		cout << "Bad input, try again: ";
		cin >> player_action;
        if (player_action == 1) {
            move_player();
        }
        else if (player_action == 2) {
        shoot_arrow();
        adjust_arrows();
        }
	}
}

/*********************************************************************
** Function: in_bounds()
** Description: checks if a memory location is accessible (in the bounds of the cave)
** Parameters: None
** Pre-Conditions: cave size was initialuzed
** Post-Conditions: must be inplement in all other functions that check boundaries
*********************************************************************/
bool Game::in_bounds(int y, int x) {
	if (x > this->size - 1  || x < 0 || y > this->size - 1 || y < 0) {
		return false;
	}
	else
		return true;
}

/*********************************************************************
** Function: check_event()
** Description: checks if an event is located in a room of a cave
** Parameters: None
** Pre-Conditions: cave size and player were initialuzed
** Post-Conditions: ends the game if the right conditions are met
*********************************************************************/
void Game::check_event() {
	if (cave[p1->current_y_coord][p1->current_x_coord].get_event_ptr() == NULL) {
        return;
    }
    // wumpus
    if (cave[p1->current_y_coord][p1->current_x_coord].get_event_ptr()->get_event_name() ==  "W") {
		cout << "You have walked into the room of the Wampus and have been eaten. Game over. " << endl;
		game_over = true;
	}
	// bats
	else if (cave[p1->current_y_coord][p1->current_x_coord].get_event_ptr()->get_event_name() == "B") {
		cout << "You walked into a room with super bats! They have taken you to a new location." << endl;
        cave[p1->current_y_coord][p1->current_x_coord].set_player_ptr(NULL);
        shift_player();
	}
	// gold
	else if (cave[p1->current_y_coord][p1->current_x_coord].get_event_ptr()->get_event_name() == "G") {
		cout << "You have found gold!" << endl;
		p1->has_gold = true;
        delete cave[p1->current_y_coord][p1->current_x_coord].get_event_ptr();
        cave[p1->current_y_coord][p1->current_x_coord].set_event_ptr(NULL);
	}
	// pits
	else if (cave[p1->current_y_coord][p1->current_x_coord].get_event_ptr()->get_event_name() == "P") {
		cout << "You have fallen in a pit and died. Game over." << endl;
		game_over = true;
	}
}

/*********************************************************************
** Function: check_if_won()
** Description: checks if the player won the game
** Parameters: None
** Pre-Conditions: the wampus was killed, gold was picked up, and thge current coordinates are identical to starting coordinates
** Post-Conditions: ends the game if the right conditions are met by player winning
*********************************************************************/
void Game::check_if_won() {
	if (p1->has_gold == true && p1->killed_wampus == true && p1->current_x_coord == p1->initial_x_coord && p1->current_y_coord == p1->initial_y_coord) {
		game_over = true;
        cout << "Congratulations! You won the game!" << endl;
	}
    else {
        game_over = false;
    }
}

/*********************************************************************
** Function: adjust_arrows()
** Description: decrements the number of arrows if player shoots. Stops game if there are no arrows left
** Parameters: None
** Pre-Conditions: number if arrows have been initialized to 3
** Post-Conditions: ends the game if the right conditions are met
*********************************************************************/
void Game::adjust_arrows() {
	if (p1->arrows == 0) {
		cout << "You do not have any more arrows! Game over." << endl;
		game_over = true;
	}
	else p1->arrows--;
}

/*********************************************************************
** Function: shoot_arrows()
** Description: shoots an arroe according to the direction the user inputs
** Parameters: None
** Pre-Conditions: bounds are checked prior to shooting an arrow or event
** Post-Conditions: kills the wampus if it hits it in the range of three rooms
*********************************************************************/
void Game::shoot_arrow() {
    string arrow_direction;
    cout << "What direction would you like to shoot? " << endl;
    cin >> arrow_direction;
    int temp_x = p1->current_x_coord;
    int temp_y = p1->current_y_coord;
	if (arrow_direction == "w") { // up
		//loop until arrow moves 3 places or hits wall
		for (int i = 1; i < 4; i++) {
			temp_x = p1->current_x_coord;
			temp_y = p1->current_y_coord - i;
			if ((in_bounds(temp_y, temp_x) == true) && (cave[temp_y][temp_x].get_event_ptr() != NULL) && (cave[temp_y][temp_x].get_event_ptr()->get_event_name() == "W")) {
				cout << "You have killed the Wumpus!" << endl;
				p1->killed_wampus = true;
                delete cave[temp_y][temp_x].get_event_ptr();
                cave[temp_y][temp_x].set_event_ptr(NULL);
				return;
			}
		}
	}
	else if (arrow_direction == "a") { // left
		//loop until arrow moves 3 places or hits wall
		for (int i = 1; i < 4; i++) {
			temp_x = p1->current_x_coord - i;
			temp_y = p1->current_y_coord;
			if ((in_bounds(temp_y, temp_x) == true) && (cave[temp_y][temp_x].get_event_ptr() != NULL) && (cave[temp_y][temp_x].get_event_ptr()->get_event_name() == "W")) {
				cout << "You have killed the Wumpus!" << endl;
				p1->killed_wampus = true;
                delete cave[temp_y][temp_x].get_event_ptr();
                cave[temp_y][temp_x].set_event_ptr(NULL);
				return;
			}
		}
	}
	else if (arrow_direction == "d") { // right
		//loop until arrow moves 3 places or hits wall
		for (int i = 1; i < 4; i++) {
			temp_x = p1->current_x_coord + i;
			temp_y = p1->current_y_coord;
			if ((in_bounds(temp_y, temp_x) == true) && (cave[temp_y][temp_x].get_event_ptr() != NULL) && (cave[temp_y][temp_x].get_event_ptr()->get_event_name() == "W")) {
				cout << "You have killed the Wumpus!" << endl;
				p1->killed_wampus = true;
                delete cave[temp_y][temp_x].get_event_ptr();
                cave[temp_y][temp_x].set_event_ptr(NULL);
				return;
			}
		}
	}
	
	else if (arrow_direction == "s") { // down
		//loop until arrow moves 3 places or hits wall
		for (int i = 1; i < 4; i++) {
			temp_x = p1->current_x_coord;
			temp_y = p1->current_y_coord + i;
			if ((in_bounds(temp_y, temp_x) == true) && (cave[temp_y][temp_x].get_event_ptr() != NULL) && (cave[temp_y][temp_x].get_event_ptr()->get_event_name() == "W")) {
				cout << "You have killed the Wumpus!" << endl;
				p1->killed_wampus = true;
                delete cave[temp_y][temp_x].get_event_ptr();
                cave[temp_y][temp_x].set_event_ptr(NULL);
				return;
			}
	    }
    }
    cout << "You did not kill the Wumpus." << endl;
    missed_arrow();
}

/*********************************************************************
** Function: play_again()
** Description: portrays options for end of the game
** Parameters: None
** Pre-Conditions: game configuration was saved and can be re-assembled in next game
** Post-Conditions: new game will start according to user input or gamw will quit entirely
*********************************************************************/
int Game::play_again() {
	int choice;
	cout << "Would you like to: " << endl;
	cout << " (1) Start game over with same cave configuration. "<< endl;
	cout << " (2) Start game over with new cave configuration" << endl; 
	cout << " (3) Quit game entirely." << endl;
	cin >> choice;
		
	if (choice == 1) {
		/// write funtion to start game with same configuration
	}
	else if (choice == 3) {
        cout << "Exiting game..." << endl;
	}
    
    return choice;
}

/*********************************************************************
** Function: missed_arrow()
** Description: moves the wampus to a different location 75% of the time if player shoots and misses an arrow
** Parameters: None
** Pre-Conditions: Wampus constructor functions properly
** Post-Conditions: New wampus object was constructed and previous one was deleted
*********************************************************************/
void Game::missed_arrow() {
    int move_wampus = rand() % 4; // generates a number from 0-3 and sets it to move_wampus
    if (move_wampus < 3) { // 75% chance 
        cout << "You woke up the Wampus! It will now move to a different room." << endl;

    for (int i = 0; i < this->size; ++i) { // Looks for the location of Wampus and deletes the event
        for (int j = 0; j<this->size; ++j) {
            if ((cave[i][j].get_event_ptr() != NULL) && (cave[i][j].get_event_ptr()->get_event_name() == "W")){
                delete cave[i][j].get_event_ptr();
                cave[i][j].set_event_ptr(NULL);
            }
        }
    }
        Event* wampus = new Wampus(); // creates a new wampus
        generate_room(wampus); // generates new roomn for wampus 
    }
    else if (move_wampus < 3) { // 25% chance
        cout << "You got lucky! You didn't wake up the Wampus although you missed!" << endl;
    }
}  


// /******************************************************************
//  * Function: ~Room()
//  * Description: class destructor. deletes memory that was allocated by constructor
//  * Parameters: None
//  * Pre-Conditions: Event_ptr object has been initialized
//  * Post-Conditions: No memory leaks
// ******************************************************************/
// Room::~Room() { // destructor
//     if (this->event_ptr != NULL) {
//         delete [] this->event_ptr;
//         this->event_ptr = NULL;
//     }
// }

// /******************************************************************
//  * Function: Room(const Room&)
//  * Description: copy constructor
//  * Parameters: const Player& p
//  * Pre-Conditions: player object has been initialized and populated
//  * Post-Conditions: a second identical player object is created without deleting the memory
// ******************************************************************/
// Room::Room(const Room & r) { // copy constructor
//     // member-wise copy
//     this->event_ptr = r.event_ptr;
//     this->adventurer = r.adventurer;

// } 

// /******************************************************************
//  * Function: operator=(const Roomr&)
//  * Description: Operator assignment overload. Deep copies a player object
//  * Parameters: const Room& r
//  * Pre-Conditions: room object has been initialized and populated
//  * Post-Conditions: a second identical room object is created.
// ******************************************************************/
// Room& Room::operator=(const Room & r) {
//     // member-wise copy
//     this->event_ptr = r.event_ptr;
//     this->adventurer = r.adventurer;

//     // free the memory first
//     if (this->event_ptr != NULL) { 
//         delete [] this->event_ptr;
//     }

//     // deep copy


//     return *this;

// }