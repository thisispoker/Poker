#include "deck.h"
#include "hand.h"
#include "card.h"

#include <unistd.h>

using namespace std;
#include <iostream>

//Stupid little helper function to print a vector of cards, for debugging
void printVec(vector<Card> v)
{
	for(Card c: v)
		cout << c.toString() << ", ";
	cout << endl;
}

int main()
{
	srand(time(NULL)); //Should only be done once!
	//Note this will seed in the same way in a given second,
	//so you will get the same results if you run more than once
	//in a second.


	//Create a shuffled deck, draw five cards, look for a pair
	Deck d(true);
	Game game;	
	Hand player(game);	//Hands require a game for context (texas holdem river, etc.)
	for(int i = 0;i < 5;i++)
		player.drawCard(d);

	if(player.isPair())
		cout << "Player has a pair!" << endl;
	else
		cout << "Player does not have a pair." << endl;

	

}