//
//  Player.h
//  332lab3
//
//  Created by Adela Gao on 3/31/15.
//  Copyright (c) 2015 Adela Gao, David McDonnel. All rights reserved.//Xcode is so smart.
//

#ifndef ___32lab3__Player__
#define ___32lab3__Player__

#include <stdio.h>//DO NOT include this in windows
#include <string>
#include <random>
#include <iostream>
#include <map>
#include <istream>
#include <ostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <set>
#include <cstring>
#include <exception>
#include <fstream>
#include <cmath>
#include <memory>
#include "Hand.h"
#include "card.h"
#include "Deck.h"
#include "fileParser.h"

using namespace std;
struct Player{
    string playerName;
    Hand playerCards;
    unsigned int numHandsWon;
    unsigned int numHandsLost;
    Player();
};




#endif /* defined(___32lab3__Player__) */
