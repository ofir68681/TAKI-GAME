#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include <string>
#include <vector>

/* Ofir Katz 314962101*/
/* Ben Horn 208569848*/

class Player {
private:
	 std::string name;
	 int num_of_cards;
	std::vector <Card> cards; // container of cards
	// more private members
	void takeCard();
	void replaceCard(Card &current ,int indx);
	
public: 
	~Player();
	Player(std::string name, int num_of_cards) ; //default construtor and init list constructor	
	Player(Player& p);// copy construtor
	Player(); //construtor and init list constructor


	bool play(Card& current);
	//the function get the current card on the table, return true if played, false if took a card from the deck
	
	int numberOfCards();
	//the function return the number of card he has.

	std::string getNameOfPlayer();

	Player& operator=(const Player& other); // Assignment operator
	
};
#endif



//
//	Card(const Card& card) : clr{card.clr}, s{card.s} {}; //copy constructor
//	Card& operator=(const Card& card) {clr = card.clr; s = card.s; return *this;}; //operator=
