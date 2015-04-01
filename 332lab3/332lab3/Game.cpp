//
//  Game.cpp
//  332lab3
//
//  Created by Adela Gao on 3/31/15.
//  Copyright (c) 2015 Adela Gao, David McDonnel. All rights reserved.
//

#include "Game.h"
#include "Player.h"
static shared_ptr<Game> gamePtr(){
    shared_ptr<Game> member1 = make_shared<Game>();
    member1=nullptr;
    cout<< "created a member1 variable" << endl;
    return member1;
}