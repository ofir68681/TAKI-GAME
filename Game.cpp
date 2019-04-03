#include "Game.h"
#include <iostream>
#include <string>

using namespace std;

void Game::start(){
	/*
	just a sketch, I compiled but did not try to run
	*/
	
	
	//Number of players
	cout << "How many players?" << endl;
	int numberOfPlayers = 0;
	cin >> numberOfPlayers;
	if (numberOfPlayers < 1){ //can one player play?
		cout << "invaild. exit"<< endl;
		return;
	}
	
	//Number of cards
	cout << "How many cards?" << endl;
	int cardsNumber = 0;
	cin >> cardsNumber;
	if (cardsNumber < 0){ //can start with 0 cards?
		cout << "invaild. exit"<< endl;
		return;
	}
	
	//initialize the players
	string name;
	Player* p;
	for(int i = 0; i < numberOfPlayers; i++){
		cout << "Player number " << (i+1) << " name?" << endl;
		cin >> name;
		//check if vaild
		p = new Player(name, cardsNumber);
		this-> players.push_back(p);
	}

	
	this-> current = new Card(Card::generate_card());
	int currentPlayer = 0; //index of current player in vector 'this->players'
	int progress = 1; // -1/1, direction of the game turns
	int nextPlayer = 1; // 0/1/2 where is thr next player from the current player
	bool gameEnd = false;
	bool playerPlay;
	while(!gameEnd){
		//print card, this->player[turnPlayer] name...
		cout << "current: " << *this->current << endl;
		cout << this->players[currentPlayer]->getNameOfPlayer() << ", your turn-" << endl;
		
		playerPlay = this->players[currentPlayer]->play(*this->current);
		
		if (playerPlay){
			switch(this->current->get_sign()){
				case sign::PLUS:
					nextPlayer = 0;
					break;
				case sign::STOP:
					nextPlayer = 2;
					break;
				case sign::CD:
					 progress = progress*-1;
					 nextPlayer = 1;
					 break;
				default:
					nextPlayer = 1;
					break;
			}
			
			/*
			if new card is -/+  -->   nextPlayer = 0
			if new card is -><-  -->   progress = progress*-1, nextPlayer = 1
			if new card is 'STOP' --> nextPlayer = 2
			otherwise, nextPlayer = 1
			*/
			
			//check if currentPlayer wins
			if(this->players[currentPlayer]->numberOfCards() == 0){
				/*print who won..*/
				cout << this->players[currentPlayer]->getNameOfPlayer() << " wins!" <<endl;
				gameEnd = true;
				continue;
			}
		}else nextPlayer = 1; 	
		
		//calculate next player index
		currentPlayer += nextPlayer * progress;
		if(currentPlayer < 0) 
			currentPlayer += numberOfPlayers;
		currentPlayer = currentPlayer % numberOfPlayers;
	}
	 	
}

Game::Game(){
}


Game::~Game(){
int end=players.size();
	 for (int i=0; i <end; i++) {
		Player* p = this->players[0];
		players.erase(players.begin());
		delete p;
	}

	delete this->current;
	//delete this;

}

Game& Game::operator=(const Game& other){/*private*/}
Game::Game(const Game &t){/*privte*/}
