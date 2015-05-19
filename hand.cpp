#include "hand.h"

#include <iostream>
using namespace std;


Hand::Hand(Game context)
{
	this->context = context;
}

void Hand::drawCard(Deck & d)
{
	cards.push_back(d.getCard());
}

void Hand::arrangeCards()
{
	//Needs to be implemented - but currently poker hand methods are written
	//without assuming that cards are sorted.
	/*
	for(size_t i = 0; i < cards.size(); i++)
	{
		for(size_t j = 0; j < i; i++)
		{
			if()
		}
	}
	*/
}

vector<Card> Hand::getCardsWithSuit(int suit)
{
	vector<Card> ret;

	for(auto curr_card: cards)
	{
		if(suit == curr_card.suit)
		{
			ret.push_back(curr_card);
		}
	}

	return ret;
}

int Hand::getNumCardsWithSuit(int suit)
{
	return getCardsWithSuit(suit).size();
}

vector<Card> Hand::getCardsWithNum(int num)
{
	vector<Card> ret;

	for(auto curr_card: cards)
	{
		if(num == curr_card.num || (num == 14 && curr_card.num == 1))
		{
			ret.push_back(curr_card);
		}
	}

	return ret;
}

int Hand::getNumCardsWithNum(int num)
{
	return getCardsWithNum(num).size();
}

bool Hand::isPair()
{
	return getPair().size() > 0;
}

vector<Card> Hand::getPair()
{
	for (int i = 14;i > 1;i--)
	{
		auto cardsWithNum = getCardsWithNum(i);
		//cout << "cwnum count " << cardsWithNum.size() << endl;
		if(cardsWithNum.size() == 2)
			return cardsWithNum;
	}
	return vector<Card>();
}

Card Hand::getCardWithNum(int num)
{
	for(auto card : cards)
	{
		if(card.num == num)
			return card;
	}
	return Card();
}

bool Hand::isTwoPair()
{
	return getTwoPair().size() > 0;
}

vector<Card> Hand::getTwoPair()
{
	bool foundOnePair = false;
	vector<Card> result;
	for (int i = 14;i > 1;i--)
	{
		auto cardsWithNum = getCardsWithNum(i);
		//cout << "cwnum count " << cardsWithNum.size() << endl;
		if(cardsWithNum.size() == 2)
		{
			if(foundOnePair)
			{
				result.push_back(cardsWithNum[0]);
				result.push_back(cardsWithNum[1]);
				return result;
			}
			else
			{
				result = cardsWithNum;
				foundOnePair = true;
			}
		}
	}
	return vector<Card>();
}

bool Hand::isThreeOfKind()
{
	return getThreeOfKind().size() > 0;
}

vector<Card> Hand::getThreeOfKind()
{
	for (int i = 14;i > 1;i--)
	{
		auto cardsWithNum = getCardsWithNum(i);
		//cout << "cwnum count " << cardsWithNum.size() << endl;
		if(cardsWithNum.size() == 3)
			return cardsWithNum;
	}
	return vector<Card>();
}

bool Hand::isStraight()
{
	return getStraight().size() > 0;
}

vector<Card> Hand::getStraight()
{
	int high = 14;
	while(high >= 5)
	{
		vector<Card> result;
		for(int curr = high;curr > high-5;curr--)
		{
			Card search = getCardWithNum(curr);
			if(search.num != -1)
			{
				//Found the card
				result.push_back(search);
				if(result.size() == 5)
					return result;
			}
			else
			{
				high = curr-1;
				break;
			}
		}
	}
	return vector<Card>();
}

bool Hand::isFlush()
{
	return getFlush().size() > 0;
}
vector<Card> Hand::getFlush()
{
	int suit = CLUBS;
	for (;suit != SPADES;suit++)
	{
		vector<Card> cardsWithSuit = getCardsWithSuit(suit);
		if(cardsWithSuit.size() == 5)
			return cardsWithSuit;
	}
	vector<Card> cardsWithSuit = getCardsWithSuit(suit);
	if(cardsWithSuit.size() == 5)
		return cardsWithSuit;
	else
		return vector<Card>();
}

bool Hand::isFourOfKind()
{
	return getFourOfKind().size() > 0;
}

vector<Card> Hand::getFourOfKind()
{
	for (int i = 14;i > 1;i--)
	{
		auto cardsWithNum = getCardsWithNum(i);
		//cout << "cwnum count " << cardsWithNum.size() << endl;
		if(cardsWithNum.size() == 4)
			return cardsWithNum;
	}
	return vector<Card>();
}