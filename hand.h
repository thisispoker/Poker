#ifndef HAND_H
#define HAND_H

#include <algorithm>
#include "card.cpp"
#include "deck.h"
#include "game.h"

class Hand
{
	/*
	 * TODO
	 *
	 * We'll need to rewrite the poker hands methods to fit with texas holdem...
	 * Also - fix up access modifiers
	 */
	public:
		//Constructor
		Hand(Game context);

		Card getHighCard();

		bool isPair();
		vector<Card> getPair();

		bool isTwoPair();
		vector<Card> getTwoPair();

		bool isThreeOfKind();
		vector<Card> getThreeOfKind();

		bool isStraight();
		vector<Card> getStraight();

		bool isFlush();
		vector<Card> getFlush();

		bool isFullHouse();					//Not yet implemented
		vector<Card> getFullHouse();		//Not yet implemented

		bool isFourOfKind();
		vector<Card> getFourOfKind();

		bool isStraightFlush();				//Not yet implemented
		vector<Card> getStraightFlush();	//Not yet implemented

		void drawCard(Deck & d);
		void arrangeCards();				//Not yet implemented

		vector<Card> getCardsWithSuit(int suit);
		vector<Card> getCardsWithNum(int num);

		int getNumCardsWithSuit(int suit);
		int getNumCardsWithNum(int num);
	private:
		vector<Card> cards;
		Card getCardWithNum(int num);
		Game context;
};



#endif