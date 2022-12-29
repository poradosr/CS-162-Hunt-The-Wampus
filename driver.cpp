#include <string>
#include <vector>
#include <iostream>
#include "event.h"
#include "room.h"
#include "game.h"
#include "player.h"

/******************************************************
** Program: driver.cpp
** Author: Raz Poradosu
** Date: 11/20/2022
** Description: A game of hunt the wampus where a player must collect the gold, kill the
    Wampus, and return to the escape room in order to win. 
** Input: a character to depict whether to play in debug mode, an integer creating a grid size
    directions to move, directions to shoot an arrow, an integer depicting if the user wants to play again
** Output: A full game of Hunt the Wampus, allowing player to play again with the same or different cave
    configuration
******************************************************/

using namespace std;

int main() {
    int play_again = 1;
    do {
        srand (time(NULL)); // initialize random seed
        Game g;

        g.start_game(); // starts the game builds and initializes grid size
        bool game_type = g.debug_mode(); // asks the player whether they would like to play in debug mode
        g.populate_empty(); // populates the cave with NULL pointers
        g.populate_cave(); // populates cave with events 
        g.coordinates_player(); // places the player in a random cave room
        if (game_type == true) {
            g.print_cave(); // print the cave layout in debug mode
            g.print_percepts(); // prints percepts if player is located one room adjacent to an event
            g.run_game(); // runs game until player dies
        }
        else if (game_type == false) {
            g.print_cave_non_debug(); // print the cave layout in non-debug mode
            g.print_percepts(); // prints percepts if player is located one room adjacent to an event
            g.run_game_non_debug(); // runs game until player dies
        }
        cout << "Would you like to play again? ";
        cin >> play_again;
    } while (play_again==1);

}