//		David McDonnel				//
//		WUID #: 420325				//
//		email : dmcdonnel@wustl.edu	//
//		3/4/2015					//
//		CSE 332: lab 2				//
//////////////////////////////////////
#ifndef Deck_h
#define Deck_h
#include "stdafx.h"
#include "fileParser.h"
#include <vector>
#include <string>
#include "card.h"
#include "Hand.h"
class Hand;
using namespace std;


class Deck
{
	friend const bool & operator<< (const ostream &, const Deck &);
	friend void dostuff(Deck &);
	friend bool check_valid(string word);
	vector<Card> cards;
	int size_;
	void Deck::load(char * filename);
	int const Deck::size() const;
	friend void operator<< (Hand &, Deck &);
public:
	Deck(char * filename);
	error_type Deck::shuffle();
	//template<class RandomIt, class UniformRandomNumberGenerator>
	//void shuffle(RandomIt, RandomIt,UniformRandomNumberGenerator);
	//~Deck();
};
void operator<< (Hand &, Deck &);
#endif