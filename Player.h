#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include <string>
#include <vector>

class Player {
private:
	 string name;
	 int num_of_cards;
	std::vector <Cards*> cards; // container of cards
	// more private members

public: 

	Player(string name, int num_of_cards) : name{clr}, num_of_cards{num_of_cards}; //default construtor and init list constructor	
	Player(Card c);// copy construtor
	Player() :name{"ugly"}, num_of_cards{8}; //construtor and init list constructor


	bool play(Card& current);
	//the function get the current card on the table, return true if played, false if took a card from the deck
	
	int numberOfCards();
	//the function return the number of card he has.
	
};
#endif



//
//	Card(const Card& card) : clr{card.clr}, s{card.s} {}; //copy constructor
//	Card& operator=(const Card& card) {clr = card.clr; s = card.s; return *this;}; //operator=
