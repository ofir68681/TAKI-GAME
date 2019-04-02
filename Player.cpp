#include "Player.h"



Player::Player(string name, int num_of_cards) : name{clr}, num_of_cards{num_of_cards}{
	for(int i=0; i<this.num_of_cards; i++){
		Card::Card* c = new Card::Card(Card::generate_card());
		this.cards.push_back(c); 
	}
}

Player::Player():name{"ugly"}, num_of_cards{8}{
	for(int i=0; i<this.num_of_cards; i++){
		Card::Card* c = new Card::Card(Card::generate_card());
		this.cards.push_back(c); 
	}
}

Player::Player(Player p){
	this.num_of_cards=p.num_of_cards;
	this.name=p.name;
	for(int i=0; i<p.num_of_cards; i++){
		this.cards.push_back(p.cards[i]); 
	}
}


bool Player::play(Card& current){
	return true;
}
int Player::numberOfCards(){ 
	return 0;
}



