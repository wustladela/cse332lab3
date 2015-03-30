//		David McDonnel				//
//		WUID #: 420325				//
//		email : dmcdonnel@wustl.edu	//
//		3/4/2015					//
//		CSE 332: lab 2				//
//////////////////////////////////////

#ifndef card_h
#define card_h
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct Card
{
public:
	char suit;
	string value;
	enum valid_suits
	{
		C = 1
		, c = 2
		, D = 3
		, d = 4
		, H = 5
		, h = 6
		, S = 7
		, s = 8
	};
	enum valid_values
	{
		two = 1
		, three = 2
		, four = 3
		, five = 4
		, six = 5
		, seven = 6
		, eight = 7
		, nine = 8
		, ten = 9
		, J = 10
		, Q = 11
		, K = 12
		, A = 13
		, j = 14
		, q = 15
		, k = 16
		, a = 17
	};
	Card();
	Card(char, string);


	string Card::returnCard();
	string Card::suitCheck(char suit);
	string Card::valueCheck(string value);
	int const Card::suitToIntHelp(char suit) const;
	int const Card::valueToIntHelp(string value) const;
	int Card::suitToInt(char suit_);
	int Card::valueToInt(const string value_);

	int const Card::suitToInt() const;
	int const Card::valueToInt() const;
};
const bool & operator< (const Card &, const Card &);
#endif