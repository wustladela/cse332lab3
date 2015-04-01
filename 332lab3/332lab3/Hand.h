//
//  Hand.h
//  332lab3
//
//  Created by Adela Gao on 3/29/15.
//  Copyright (c) 2015 Adela Gao, David McDonnel. All rights reserved.
//

#ifndef ___32lab3__Hand__
#define ___32lab3__Hand__

#include <stdio.h>
#include <vector>
#include <string>
#include "Deck.h"

class Deck;
using namespace std;

class Hand
{
    vector<Card> hand_;
    mutable int size_;
    int const size();
    Card& operator[](size_t);
    void remove_card(size_t);
    const bool operator== (const Hand &) const;
    friend void operator<< (const ostream &, const Hand &);
    friend void
    operator<< (Hand &,Deck &);
    friend const bool poker_rank(const Hand &, const Hand &);
    friend void printHands(vector<Hand>&);
    friend void dostuff(Deck &);
    //friend void Deck::load(char *);
public:
    Hand();
    Hand(const Hand &);
    Hand(const vector<Card> &);
    //~Hand();
    string const as_string();
    void printHands(vector<Hand>&);
    void dostuff(Deck &);
    Hand operator= (const Hand &);
    const bool operator< (const Hand &) const;
};
template<class T>
bool lessThan(T &, T &);
const bool poker_rank(const Hand &, const Hand &);
#endif /* defined(___32lab3__Hand__) */
