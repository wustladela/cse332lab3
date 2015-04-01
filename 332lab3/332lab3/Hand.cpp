//
//  Hand.cpp
//  332lab3
//
//  Created by Adela Gao on 3/29/15.
//  Copyright (c) 2015 Adela Gao, David McDonnel. All rights reserved.
//

//		David McDonnel				//
//		WUID #: 420325				//
//		email : dmcdonnel@wustl.edu	//
//		3/4/2015					//
//		CSE 332: lab 2				//
//////////////////////////////////////

//#include "stdafx.h"
#include <vector>
#include <string>
#include <algorithm>
#include "Hand.h"
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

Hand::Hand(const vector<Card> &h){
    hand_ = h;
    size_ = 5;
}

//Hand::~Hand()
//{
//	delete &size_;
//	delete[] & hand_;
//}

Hand Hand::operator= (const Hand &h)
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
    else{
        return *this;
    }
}

int const Hand::size()
{
    return size_;
}


const bool Hand::operator== (const Hand &h) const
{
    if (this != &h)
    {
        return false;
    }
    else return true;
}


const bool Hand::operator< (const Hand &h) const
{
    return this->hand_[0] < h.hand_[0];
}

string const Hand::as_string()
{
    string out = "";
    bool at_least_one_card = false;
    vector<Card> temp = hand_;
    for (Card c : hand_)
    {
        if (c.returnCard() != "false")
        {
            at_least_one_card = true;
            out = out + c.value + c.suit + " ";
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
    for (unsigned int i = 0; i < h.hand_.size(); ++i){
        Card temp2 = h.hand_[i];
        temp += temp2.returnCard() + " ";
    }
    cout << temp << endl;
}

void operator<< (Hand &h,Deck &d)
{
    if (!d.cards_.empty()){
        h.hand_.push_back(d.cards_.back());
        d.cards_.pop_back();
        sort(h.hand_.begin(),h.hand_.end(), lessThan<Card>);
        ++size_;
    }
}

template<class T>
bool lessThan(T &card1, T &card2)
{
    return card1 < card2;
}


const bool poker_rank(const Hand &h1, const Hand &h2)
{
    if (getRank(h1.hand_) > getRank(h2.hand_)){
        return true;
    }
    else return false;
    
}
