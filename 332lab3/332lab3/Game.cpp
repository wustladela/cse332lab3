//
//  Game.cpp
//  332lab3
//
//  Created by Adela Gao on 3/31/15.
//  Copyright (c) 2015 Adela Gao, David McDonnel. All rights reserved.
//

#include "Game.h"
#include "Player.h"

//TODO: Step 7: That pointer should be initialized to be singular (point to nothing).
shared_ptr<Game> Game::instance(){
    if (this->gamePtr==nullptr) {
        throw "instance not available";
    }
    else{
        return this->gamePtr;
    }
}

void start_game(const string& gameString){
    if (&gameString!=NULL) {//TODO: weird? but compiler said so
        throw "game already started";
    }
    else if (!gameString.find("FiveCardDraw")){
        throw "unknown game";
    }
    else{
        //shared_ptr<FiveCardDraw> = make_shared<FiveCardDraw>("what?? TODO");
        //this->gamePtr=TODO
    }
}
void Game::stop_game(){
    if (this->gamePtr==nullptr) {
        throw "no game in progress";
    }
    
}
void Game::add_player(const string& playerName){
    if (find(this->allPlayers->begin(), this->allPlayers->end(), playerName) != this->allPlayers->end()) {
        throw "already playing";
    }
    else{
        shared_ptr<Player> newPlayer = make_shared<Player>(playerName);
        //this->allPlayers->push_back(newPlayer);//??????TODO
    }
}
//TODO below: Return what?
int Game::before_return (Player&){
    return 0;
}
int Game::turn (Player&){
    return 0;
}
int Game::after_turn (Player&){
    return 0;
}
int Game::before_round(){
    return 0;
}
int Game::round(){
    return 0;
}
int Game::after_round(){
    return 0;
}

