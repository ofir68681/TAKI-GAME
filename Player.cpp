#include "Player.h"




using namespace std;

Player::Player(string name, int num_of_cards): name{name}, num_of_cards{num_of_cards}{
	for(int i=0; i<this->num_of_cards; i++){
		Card c(Card::generate_card());
		this->cards.push_back(c); 
	}
}

Player::Player() :name{""}, num_of_cards{0}{
	for(int i=0; i< this->num_of_cards; i++){
		Card c(Card::generate_card());
		this->cards.push_back(c); 
	}
}

Player::Player( Player &p){
	this->num_of_cards=p.num_of_cards;
	this->name=p.name;
	for(int i=0; i<p.num_of_cards; i++){
		Card c(Card::generate_card());
		this->cards.push_back(c); 
	}
}


bool Player::play(Card& current){
	cout << "your cards: ";
	for(int i=0; i<cards.size(); i++){
		cout << "(" << (i+1) << ")" << cards[i]<< " ";
	}
	cout << endl;
	
	
	bool flag = false;
	
	
	int chs;
	while(!flag){
		cin >>  chs;
		
		if(chs > this->cards.size() || chs <= 0){ //illegal input
			takeCard();
			return false;
		}
		
		Card choosen = cards[chs -1];
		if(current.is_legal(choosen)){
			flag = true;
			replaceCard(current, chs -1);
			return true;
		}
		else{
			cout<< "You can't put "<< (cards[chs -1]) << " on " << current << endl;
		}
	}
	
	return false;
}

int Player::numberOfCards(){ 
	return this->cards.size();
}

void Player::takeCard(){
	Card c(Card::generate_card());
	num_of_cards++;
	this->cards.push_back(c); 
}

void Player::replaceCard(Card &current ,int indx){
	current= cards[indx];
	cards.erase(cards.begin()+indx);
	num_of_cards--;
}

std::string Player::getNameOfPlayer(){
	return this->name;
}

Player::~Player(){
	for(int i=0; i<this->cards.size(); i++){
		cards.erase(cards.begin());
	}
}

Player::Player& operator=(const Player& other){
	this->num_of_cards=p.num_of_cards;
	this->name=p.name;
	for(int i=0; i<p.num_of_cards; i++){
		Card c(Card::generate_card());
		this->cards.push_back(c); 
	}
	
}



