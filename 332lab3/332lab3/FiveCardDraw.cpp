//
//  FiveCardDraw.cpp
//  332lab3
//
//  Created by Adela Gao on 4/2/15.
//  Copyright (c) 2015 Adela Gao, David McDonnel. All rights reserved.
//

#include "FiveCardDraw.h"
FiveCardDraw::FiveCardDraw(){
    this->dealerPos=0;
}
/**
 TODO:
 and then iterates through all of the 52 valid combinations of suit and rank as defined in the Card class enumerations
 and passes a Card corresponding to each combination 
 into a call to the add_card method of the main deck member variable that was inherited from the Game base class
**/