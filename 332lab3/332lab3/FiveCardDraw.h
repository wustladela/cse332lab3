//
//  FiveCardDraw.h
//  332lab3
//
//  Created by Adela Gao on 4/2/15.
//  Copyright (c) 2015 Adela Gao, David McDonnel. All rights reserved.
//

#ifndef ___32lab3__FiveCardDraw__
#define ___32lab3__FiveCardDraw__

#include <stdio.h>
#include "Game.h"

class FiveCardDraw: public Game{
protected:
    size_t dealerPos;
    Deck protectedDeck;
public:
    FiveCardDraw();
    int virtual before_turn(Player&) = 0;
};



#endif /* defined(___32lab3__FiveCardDraw__) */
