//
//  Player.cpp
//  332lab3
//
//  Created by Adela Gao on 3/31/15.
//  Copyright (c) 2015 Adela Gao, David McDonnel. All rights reserved.
//

#include "Player.h"
Player::Player(string filename){
    this->playerName=filename;
    ifstream infile(filename);
    cout << "filename is " << filename << endl;
    ifstream ifs;
    ifs.open(filename);
    if (ifs.good()){
        string line;
        int count = 0;//we only try to read 2 values from it, aka wins and losses
        while (getline(ifs, line) && count<2)
        {
            if (count==0) {
                int temp;
                istringstream buffer(line);
                buffer >> temp;
                this->numHandsWon =temp;
                ++count;
            }
            else if (count==1){
                int temp;
                istringstream buffer(line);
                buffer >> temp;
                this->numHandsLost=temp;
                ++count;
            }
            else{
                this->numHandsWon=0;
                this->numHandsLost=0;
                break;
            }
        }
    
        }
    else{
        this->numHandsWon=0;
        this->numHandsLost=0;
    }
    
}