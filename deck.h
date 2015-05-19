#ifndef DECK_H
#define DECK_H

#include "card.cpp"

#include <vector>
using std::vector;

class Deck
{
	public:
		Deck(bool shuffled);
		Card getCard();
		int getNumCards();
	private:
		vector<Card> cards;
		void shuffle();
};

#endif