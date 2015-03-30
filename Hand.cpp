//		David McDonnel				//
//		WUID #: 420325				//
//		email : dmcdonnel@wustl.edu	//
//		3/4/2015					//
//		CSE 332: lab 2				//
//////////////////////////////////////

#include "stdafx.h"
#include <vector>
#include <string>
#include <algorithm>
#include "Hand.h"
#include "Deck.h"
#include "card.h"
#include <sstream>
using namespace std;

vector<Card> hand_;
int size_;

Hand::Hand(){}

Hand::Hand(const Hand &h)
{
	hand_ = h.hand_;
	size_ = hand_.size();
}

//Hand::~Hand()
//{
//	delete &size_;
//	delete[] & hand_;
//}

Hand & Hand::operator= (const Hand &h)
{
	if (this != &h){
		try{
			hand_ = h.hand_;
		}
		catch (...){
			delete[] & hand_;
			throw;
		}
		return *this;
	}
}

int const Hand::size()
{
	return size_;
}


const bool & Hand::operator== (const Hand &h) const
{
	if (this != &h)
	{
		return false;
	}
	else return true;	
}


const bool & Hand::operator< (const Hand &h) const
{
	for (int i = 0; i < 5; ++i)
	{
		if (hand_[i] < h.hand_[i])
		{
			return true;
		}
	}
}

string const Hand::as_string()
{
	string out = "";
	bool at_least_one_card = false;
	stringstream ss;
	string s;
	for each (Card c in hand_)
	{
		if (c.returnCard() != "false")
		{
			at_least_one_card = true;
			ss << c.suit;
			ss >> s;
			out = out + c.value + s + " ";
		}
		else
		{
			error_handler(Invalid_Card_as_string);
		}
	}
	if (!at_least_one_card)
	{
		error_handler(No_valid_cards_in_vector);
	}
	return out;
}

void operator<< (const ostream &os, const Hand &h)
{
	string temp = "";
	for (int i = 0; i < h.hand_.size(); ++i){
		Card temp2 = h.hand_[i];
		temp += temp2.returnCard() + " ";
	}
	cout << temp << endl;
}

void operator<< (Hand &h,Deck &d)
{
	if (!d.cards.empty()){
		h.hand_.push_back(d.cards[0]);
		sort(h.hand_.begin(),h.hand_.end(), lessThan<Card>);
		++size_;
	}
}

const bool poker_rank(const Hand &h1, const Hand &h2)
{
	if (h2.hand_[0] < h1.hand_[0])
	{
		return true;
	}
	else return false;
}