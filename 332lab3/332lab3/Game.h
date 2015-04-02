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
    shared_ptr<vector<Player>> allPlayers;
    
public:
    void add_player(const string&);
    void stop_game();//how to make static?
    static shared_ptr<Game> instance();//how to  make static?
    void start_game(const string&);
    int virtual before_return (Player&)=0;
    int virtual turn (Player&)=0;
    int virtual after_turn (Player&)=0;
    int virtual before_round ()=0;
    int virtual round ()=0;
    int virtual after_round ()=0;
};




#endif /* defined(___32lab3__Game__) */
