//		David McDonnel				//
//		WUID #: 420325				//
//		email : dmcdonnel@wustl.edu	//
//		3/4/2015					//
//		CSE 332: lab 2				//
//////////////////////////////////////
#ifndef Hand_h
#define Hand_h
#include "stdafx.h"
#include <vector>
#include <string>
#include "Deck.h"
class Deck;
#include "card.h"
using namespace std;

class Hand
{
	vector<Card> hand_;
	mutable int size_;
	int const Hand::size();
	
	const bool & Hand::operator== (const Hand &) const;
	friend void Hand::operator<< (const ostream &, const Hand &);
	friend void Hand::operator<< (Hand &,Deck &);
	friend const bool poker_rank(const Hand &, const Hand &);
	friend void printHands(vector<Hand>&);
	friend void dostuff(Deck &);
public:
	Hand::Hand();
	Hand::Hand(const Hand &);
	//~Hand();
	string const Hand::as_string();
	void printHands(vector<Hand>&);
	void dostuff(Deck &);
	Hand & Hand::operator= (const Hand &);
	const bool & Hand::operator< (const Hand &) const;
};
#endif