#ifndef CARD_H
#define CARD_H

#include <vector>
using std::vector;

#include <string>
using std::string;

enum Suit {CLUBS, DIAMONDS, HEARTS, SPADES};

class Card
{
	public:
		short num;
		Suit suit;
		Card(short _num,Suit _suit)
		{
			num = _num;
			suit = _suit;
		}
		string toString()
		{
			return std::to_string(num) + " of " + std::to_string(suit);
		}

};



#endif