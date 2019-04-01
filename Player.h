#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
class Player {
private:
	// name;
	// num_of_cards;
	// container of cards
	// more private members

public:
	bool play(Card& current);
	//the function get the current card on the table, return true if played, false if took a card from the deck
	
	int numberOfCards();
	//the function return the number of card he has.
	
};
#endif



