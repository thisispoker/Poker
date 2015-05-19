#include "deck.h"
#include <random>
#include <time.h>

#include <algorithm>
#include <utility>
using std::swap;

using namespace std;
#include <iostream>

Deck::Deck(bool shuffled)
{
	for(short i = 1;i <= 13;i++)
	{
		cards.push_back(Card(i,CLUBS));
		cards.push_back(Card(i,DIAMONDS));
		cards.push_back(Card(i,HEARTS));
		cards.push_back(Card(i,SPADES));			
	}
	if (shuffled)
		shuffle();
}

void Deck::shuffle()
{
	short n = cards.size();
	for(short i = 0;i < n;i++)
	{
		int r = i + (rand() % (n-i));
		iter_swap(cards.begin()+i,cards.begin()+r);
	}
}

Card Deck::getCard()
{
	Card card = cards[0];
	cards.erase(cards.begin());
	return card;
}

int Deck::getNumCards()
{
	return cards.size();
}