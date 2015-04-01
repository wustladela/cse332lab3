//
//  fileParser.h
//  332lab3
//
//  Created by Adela Gao on 3/29/15.
//  Copyright (c) 2015 Adela Gao, David McDonnel. All rights reserved.
//

#ifndef ___32lab3__fileParser__
#define ___32lab3__fileParser__

#include <stdio.h>
//		David McDonnel				//
//		WUID #: 420325				//
//		email : dmcdonnel@wustl.edu	//
//		3/4/2015					//
//		CSE 332: lab 2				//
//////////////////////////////////////

//#ifndef fileParser_h
//#define fileParser_h
//#include "stdafx.h"
#include "card.h"
#include "Hand.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;


enum program_info { name = 0, filename, args };
enum hand { end_of_hand_range = 4, hand_range = 5 };
enum params { hand_size = 5, cards_dealt = 45, players = 9};
enum rank
{
    no_rank = 0
    , one_pair
    , two_pair
    , three_of_a_kind
    , straight
    , is_flush
    , full_house
    , four_of_a_kind
    , straight_flush
};
enum error_type
{
    no_error = 0
    , Incorrect_card_value = -1
    , Failed_to_open_file = -2
    , Invalid_Card_passed_to_output_stream = -3
    , Could_not_open_filestream = -4
    , No_arguments_provided = -5
    , No_valid_cards_in_vector = -6
    , Invalid_Card_as_string = -7
    , Only_shuffle = -8
    , Two_Shuffles = -9
    , Two_Files = -10
    , Shuffle_empty = -11
};

int parse(vector<Card> &, string);
int output(const vector<Card> &);
int error_handler(error_type failure_type);
string getFileName();
string getFilePath();
//void getAllRanks(vector<Hand> &);
int getRank(const vector<Card> &);
void sortVector(vector<Card> &);
template<class T>
bool lessThan(T &, T &);
#endif /* defined(___32lab3__fileParser__) */
