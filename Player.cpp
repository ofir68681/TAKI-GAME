#include "Player.h"



Player::Player(string name, int num_of_cards){
	for(int i=0; i<this.num_of_cards; i++){
		Card c=generate_card();
		this.cards.push_back(c); 
	}


}



bool Player::play(Card& current){
	return true;
}
int Player::numberOfCards(){ 
	return 0;
}



