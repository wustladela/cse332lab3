//
//  Game.h
//  332lab3
//
//  Created by Adela Gao on 3/31/15.
//  Copyright (c) 2015 Adela Gao, David McDonnel. All rights reserved.
//

#ifndef ___32lab3__Game__
#define ___32lab3__Game__

#include <stdio.h>
#include "Player.h"//the king of all header files.

class Game;

class Game{
protected:
    static shared_ptr<Game> gamePtr;
    Deck mainDeck;
    shared_ptr<Player> allPlayers;
public:
    //instance method?
    void start_game(const string&);
    
};




#endif /* defined(___32lab3__Game__) */
