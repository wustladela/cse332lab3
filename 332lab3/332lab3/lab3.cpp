//
//  main.cpp
//  332lab3
//
//  Created by Adela Gao on 3/29/15.
//  Copyright (c) 2015 Adela Gao, David McDonnel. All rights reserved.
//

#include <iostream>
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

using namespace std;

void printHands(vector<Hand> &h){
    vector<Hand>::iterator hands_it = h.begin();
    vector<Hand>::iterator hands_itEnd = h.end();
    int count = 1;
    for (hands_it; hands_it != hands_itEnd;){
        cout << "Hand" << count << ": " << endl;
        cout << hands_it->as_string() << endl;
        ++count;
        ++hands_it;
    }
}

void dostuff(Deck &d){
    cout << "hi" << endl;
    vector<Hand> hands;
    /*vector<Hand>::iterator deck_it = d.hands_.begin;
     vector<Hand>::iterator deck_itEnd = d.hands_.end;*/
    for (int i = 0; i < players; ++i)
    {
        hands.push_back(Hand::Hand());
    }
    for (int i = 0; i < cards_dealt; ++i){
        hands[i % 9] << d;
    }
    cout << "Deck: " << endl;
    cout << d;
    
    printHands(hands);
    std::sort(hands.begin(), hands.end());
    cout << "hands sorted" << endl;
    printHands(hands);
    sort(hands.begin(), hands.end(), poker_rank);
    cout << "hands sorted" << endl;
    printHands(hands);
}


int main(int argc, char * argv[])
{
    bool b = false;
    if (argc == 2)
    {
        if (string(argv[1]) == "-shuffle")
        {
            error_handler(Only_shuffle);
        }
        else
        {
            Deck d = Deck::Deck(argv[1]);
            dostuff(d);
        }
    }
    else if (argc == 3)
    {
        if (string(argv[1]) == "-shuffle" && string(argv[2]) == "-shuffle")
        {
            error_handler(Two_Shuffles);
        }
        else
        {
            if (string(argv[1]) == "-shuffle" || string(argv[2]) == "-shuffle")
            {
                if (string(argv[1]) == "-shuffle")
                {
                    Deck d = Deck::Deck(argv[2]);
                    d.shuffle();
                    dostuff(d);
                }
                else
                {
                    Deck d = Deck::Deck(argv[1]);
                    d.shuffle();
                    dostuff(d);
                }
            }
            else
            {
                error_handler(Two_Files);
            }
        }
    }
    return 0;
    
}
