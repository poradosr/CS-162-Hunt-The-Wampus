#ifndef GAME_H
#define GAME_H 

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include "event.h"
#include "wampus.h"
#include "gold.h"
#include "pits.h"
#include "bats.h"
#include "room.h"
#include "player.h"
#include "configuration.h"


using namespace std;

class Game
{
private:
    int size;
    vector <vector<Room> > cave;
    Player* p1;
    bool game_over = false;
    Configuration c;
	
public:

	Game();
	~Game();
    int get_size();
    string player_symbol(); 
    void populate_cave();
    void delete_cave();
    void generate_room(Event*);
    void print_cave();
    void print_cave_non_debug();
    bool debug_mode();
    void start_game();
    void coordinates_player();
    void shift_player(); 
    void populate_empty();
    void move_player();
    void print_percepts(); 
    void run_game();
    void run_game_non_debug();
    void get_player_action();
    bool in_bounds(int, int);
    void check_event();
    void check_if_won();
    void adjust_arrows();
    void shoot_arrow();
    int play_again();
    void missed_arrow();

};

#endif