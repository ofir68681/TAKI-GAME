#include "Player.h"



Player::Player(string name, int num_of_cards){
	for(int i=0; i<this.num_of_cards; i++){
		Card::Card* c = new Card::Card(Card::generate_card());
		this.cards.push_back(c); 
	}
}

Player::Player(){
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
	cout << "your cards: ";
	for(int i=0; i<cards.size(); i++){
		cout << "(" << i << ")" << (*cards[i])
	}
	
	
	
	
	return true;
}

int Player::numberOfCards(){ 
	return 0;
}



