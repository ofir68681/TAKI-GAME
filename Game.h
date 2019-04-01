#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Card.h"
#include <vector>

class Game {
private:
	//private members and functions
	std::vector <Player*> players;
	Card current;
public:
	//public members and functions
	void start();
};
#endif




