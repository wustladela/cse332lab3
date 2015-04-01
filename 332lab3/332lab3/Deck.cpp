//
//  Deck.cpp
//  332lab3
//
//  Created by Adela Gao on 3/29/15.
//  Copyright (c) 2015 Adela Gao, David McDonnel. All rights reserved.
//

//#include "Deck.h"
//		David McDonnel				//
//		WUID #: 420325				//
//		email : dmcdonnel@wustl.edu	//
//		3/4/2015					//
//		CSE 332: lab 2				//
//////////////////////////////////////
//#include "stdafx.h"
#include "Deck.h"

#include <algorithm>
#include <iterator>
#include <random>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<Card> cards_;
vector<Hand> hands_;
int deck_size_;

void add_card(Card & newCard){
    cards_.push_back(newCard);
}



Deck::Deck(){}

Deck::Deck(char * filename)
{
    load(filename);
    deck_size_ = hands_.size() * 5;
}
//Deck::~Deck()
//{
//	delete & deck_size_;
//	delete[] &cards;
//}
void Deck::load(char * filename)
{
    parse(cards_, filename);
    int count = 0;
    vector<Card> temp;
    for (Card i : cards_){
        temp.push_back(i);
        if (temp.size()%5 == 0){
            hands_.push_back(Hand::Hand(temp));
            temp.clear();
        }
    }
    
    ////this.cards = parse(cards, filename);
    //string bypassed = "2C 3C 4C 5C 6C 7C 8C 9C 10C JC QC KC AC";
    //bypassed += "aD kD qD jD 10D 9D 8D 7D 6D 5D 4D 3D 2D";
    //bypassed += "2h 3h 4h 5h 6h 7h 8h 9h 10h Jh Qh Kh Ah";
    //bypassed += "as ks qs js 10s 9s 8s 7s 6s 5s 4s 3s 2s";
    ////need to make other test cases
    //istringstream iss(bypassed);
    //string word;
    //int count = 0;
    //std::vector<Card> temp;
    //while (iss >> word)
    //{
    //	if (check_valid(word)){
    //		int len = word.length();
    //		char suit = word.at(len - 1);
    //		string value = word.substr(0, len - 1);
    //		Card card = Card(suit, value);
    //		temp.push_back(card);
    //		++count;
    //	}
    //}
    //if (count == 5){
    //	for (Card i : temp)
    //	{
    //		cards_.push_back(i);
    //	}
    //	Hand h = Hand::Hand(cards_);
    //	hands_.push_back(h);
    //}
}
error_type Deck::shuffle(){
    std::random_device rd;
    std::mt19937 g(rd());
    if (cards_.size() > 0){
        std::shuffle(cards_.begin(), cards_.end(), g);
        return no_error;
    }
    else{
        return Shuffle_empty;
    }
}

/*error_type shuffle(){
 
 std::random_device rd;
 std::mt19937 g(rd());
 if (cards.size() > 0){
 std::shuffle(cards.begin(), cards.end(), g);
 return no_error;
 }
 else{
 return Shuffle_empty;
 }
 
	}*/


template<class RandomIt, class UniformRandomNumberGenerator>
void shuffle(RandomIt first, RandomIt last,
             UniformRandomNumberGenerator&& g)
{
    typedef typename std::iterator_traits<RandomIt>::difference_type diff_t;
    typedef typename std::make_unsigned<diff_t>::type udiff_t;
    typedef typename std::uniform_int_distribution<udiff_t> distr_t;
    typedef typename distr_t::param_type param_t;
    
    distr_t D;
    diff_t n = last - first;
    for (diff_t i = n - 1; i > 0; --i) {
        using std::swap;
        swap(first[i], first[D(g, param_t(0, i))]);
    }
}

int const Deck::size() const
{
    return deck_size_;
}

const bool operator<< (const ostream &os, const Deck &d)
{
    try{
        output(cards_);
    }
    catch (error_type &n){
        if (error_handler(n) == 0){
            return true;
        }
        else return false;
    }
    catch (...)
    {
        return false;
    }
    return false; //CHANGE THIS?
    
}