//
//  Deck.h
//  332lab3
//
//  Created by Adela Gao on 3/29/15.
//  Copyright (c) 2015 Adela Gao, David McDonnel. All rights reserved.
//

#ifndef ___32lab3__Deck__
#define ___32lab3__Deck__

#include <stdio.h>
//		David McDonnel				//
//		WUID #: 420325				//
//		email : dmcdonnel@wustl.edu	//
//		3/4/2015					//
//		CSE 332: lab 2				//
//////////////////////////////////////
//#ifndef Deck_h
//#define Deck_h
//#include "stdafx.h"
#include "fileParser.h"
#include <vector>
#include <string>
#include "Hand.h"

class Hand;

using namespace std;


class Deck
{
    void add_card(Card &);
    friend const bool operator<< (const ostream &, const Deck &);
    friend void dostuff(Deck &);
    friend bool check_valid(string word);
    vector<Card> cards_;
    int size_;
    int const size() const;
    friend void operator<< (Hand &, Deck &);
    
public:
    Deck(char * filename);
    Deck();
    error_type shuffle();
    vector<Hand> hands_;
    void load(char * filename);
    //template<class RandomIt, class UniformRandomNumberGenerator>
    //void shuffle(RandomIt, RandomIt,UniformRandomNumberGenerator);
    //~Deck();
};
void operator<< (Hand &, Deck &);
#endif /* defined(___32lab3__Deck__) */
