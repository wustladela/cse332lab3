//
//  fileParser.cpp
//  332lab3
//
//  Created by Adela Gao on 3/29/15.
//  Copyright (c) 2015 Adela Gao, David McDonnel. All rights reserved.
//


//		David McDonnel				//
//		WUID #: 420325				//
//		email : dmcdonnel@wustl.edu	//
//		3/4/2015					//
//		CSE 332: lab 2				//
//////////////////////////////////////

//#include "stdafx.h"
#include "fileParser.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
//#include <Windows.h>
#include <wchar.h>
using namespace std;

//This function checks if a card is valid.
//It takes in a string from the input file
//and uses length and switch statements to
//determine valid strings, outputting
//whether or not there is an error
bool check_valid(string word){
    int len = word.length();
    if (len > 0 && len < 4)
    {
        char suit = word.at(len - 1);
        string value = word.substr(0, 1);
        if
            (
             suit != 'C'
             && suit != 'c'
             && suit != 'S'
             && suit != 's'
             && suit != 'H'
             && suit != 'h'
             && suit != 'D'
             && suit != 'd'
             )
        {
            return false; //Invalid suit type
        }
        else if
            (
             value != "1"
             && value != "2"
             && value != "3"
             && value != "4"
             && value != "5"
             && value != "6"
             && value != "7"
             && value != "8"
             && value != "9"
             && value != "10"
             && value != "J"
             && value != "j"
             && value != "Q"
             && value != "q"
             && value != "K"
             && value != "k"
             && value != "A"
             && value != "a"
             )
        {
            return false; //Invalid value type
        }
        else
        {
            return true; //Valid card
        }
    }
    else
    {
        return false; //Invalid encoding length
    }
}


//This function parses the input file being
//read in from the file stream. It checks for valid
//cards then pushes them to the cards vector
int parse(vector<Card> &vector, string filename)
{
    //GOOD CODE: 3 lines below
    //string s = getFilePath();
    //ifstream infile(filename);
    //ifstream ifs(s + "\\" + filename);
    
    
    
    //ifstream ifs(s + "\\" + filename);
    //cout << filename << endl;
    
    
    ////already checked at main method
    //if (ifs.good()){
    //	cout << "File successfully opened: " << filename << endl;
    //}
    //else{
    //	//usageMsg(filename, progname, -1);//when argc=-1 means file open error
    //	cout << "Cannot read file" << endl;
    //	return error_handler(Failed_to_open_file);
    //}
    //string line;
    //string word;
    ////word count for each line
    ////get lines
    //while (getline(ifs, line)){
    //	cout << "current line " << line << endl;
    //	istringstream thisline(line);
    //	//get words from line
    //	while (thisline >> word){
    //		string rankStr, suitStr;
    //		//parse word and prepare to check
    //	}
    //}
    std::vector<Card> temp;
    ifstream infile(filename);
    cout << "filename is " << filename << endl;
    ifstream ifs;
    ifs.open(filename);
    if (ifs.good())
    {
        string line;
        string word;
        int count = 0;
        
        while (getline(ifs, line))
        {
            istringstream iss(line);
            cout << "found a line!" << line << endl;
            while (iss >> word)
            {
                if (count < 5)
                {
                    
                    if (word.substr(1, 2) != "//")
                    {
                        if (check_valid(word))
                        {
                            int len = word.length();
                            char suit = word.at(len - 1);
                            string value = word.substr(0, len - 1);
                            Card card = Card(suit, value);
                            temp.push_back(card);
                            ++count;
                        }
                        else
                        {
                            --count;
                            cout << "Warning: Invalid card definition string" << endl;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
                for (Card i : temp)
                {
                    vector.push_back(i);
                }
                temp.clear();
                count = 0;
            }
        }
    }
    else
    {
        return error_handler(Failed_to_open_file);
    }
    return no_error;
}


//This function is used to print out
//all valid cards that were read in
//from the file stream
int output(const vector<Card> &_vector){
    string out = "";
    bool at_least_one_card = false;
    for (Card c : _vector)
    {
        if (c.returnCard() != "false")
        {
            at_least_one_card = true;
            out = out + c.value + c.suit + "\n";
        }
        else
        {
            return error_handler(Invalid_Card_passed_to_output_stream);
        }
    }
    if (!at_least_one_card)
    {
        return error_handler(No_valid_cards_in_vector);
    }
    cout << out << endl;
    return no_error;
}

//This creates hands, then sorts each hand, then calls a function to get the rank and returns it to cout.
//void getAllRanks(const vector<Hand> &h)
//{
//
//	/*std::vector<Card> temp;
//	std::vector<Card>::const_iterator iter;
//	std::vector<Card>::const_iterator temp_iter;
//	int hand_count = 0;
//
//	for (unsigned int i = 0; i < vector.size() - end_of_hand_range; i = i + hand_range)
//	{
//		for (unsigned int j = i; j < i + hand_range; ++j)
//		{
//			temp.push_back(vector.at(j));
//		}
//		std::sort(temp.begin(), temp.end(), lessThan<Card>);
//
//		cout << "Rank of hand " << hand_count << " is: " << getRank(temp) << endl;
//		temp.clear();
//		++hand_count;
//	}*/
//
//}
//This function generalizes the less than operator to a function call with parametrized type.
template<class T>
bool lessThan(T &card1, T &card2)
{
    return card1 < card2;
}

int getRank(const vector<Card> &vector)
{
    bool straight_ = false;
    bool flush_ = false;
    int of_a_kind1 = 1;
    int of_a_kind2 = 1;
    int of_a_kind3 = 1;
    int of_a_kind4 = 1;
    if (vector.at(0).suitToInt() == vector.at(1).suitToInt())
    {
        if (vector.at(1).suitToInt() == vector.at(2).suitToInt())
        {
            if (vector.at(2).suitToInt() == vector.at(3).suitToInt())
            {
                if (vector.at(3).suitToInt() == vector.at(4).suitToInt())
                {
                    flush_ = true;
                }
            }
        }
    }
    if (vector.at(4).valueToInt() + 1 == vector.at(3).valueToInt())
    {
        if (vector.at(3).valueToInt() + 1 == vector.at(2).valueToInt())
        {
            if (vector.at(2).valueToInt() + 1 == vector.at(1).valueToInt())
            {
                if (vector.at(1).valueToInt() + 1 == vector.at(0).valueToInt())
                {
                    straight_ = true;
                }
            }
        }
    }
    if (vector.at(4).valueToInt() == vector.at(3).valueToInt())
    {
        ++of_a_kind1;
        if (vector.at(4).valueToInt() == vector.at(2).valueToInt())
        {
            ++of_a_kind1;
            if (vector.at(4).valueToInt() == vector.at(1).valueToInt())
            {
                ++of_a_kind1;
                if (vector.at(4).valueToInt() == vector.at(0).valueToInt())
                {
                    ++of_a_kind1;
                }
            }
            else
            {
                if (vector.at(1).valueToInt() == vector.at(0).valueToInt())
                {
                    ++of_a_kind4;
                }
            }
        }
        else
        {
            if (vector.at(4).valueToInt() == vector.at(1).valueToInt())
            {
                ++of_a_kind1;
                if (vector.at(4).valueToInt() == vector.at(0).valueToInt())
                {
                    ++of_a_kind1;
                }
            }
            else
            {
                if (vector.at(1).valueToInt() == vector.at(0).valueToInt())
                {
                    ++of_a_kind4;
                }
            }
        }
        if (vector.at(2).valueToInt() == vector.at(1).valueToInt())
        {
            ++of_a_kind3;
            if (vector.at(2).valueToInt() == vector.at(0).valueToInt())
            {
                ++of_a_kind3;
            }
        }
        else
        {
            if (vector.at(1).valueToInt() == vector.at(0).valueToInt())
            {
                ++of_a_kind4;
            }
        }
    }
    else
    {
        if (vector.at(3).valueToInt() == vector.at(2).valueToInt())
        {
            ++of_a_kind2;
            if (vector.at(3).valueToInt() == vector.at(1).valueToInt())
            {
                ++of_a_kind2;
                if (vector.at(3).valueToInt() == vector.at(0).valueToInt())
                {
                    ++of_a_kind2;
                }
            }
            else
            {
                if (vector.at(1).valueToInt() == vector.at(0).valueToInt())
                {
                    ++of_a_kind4;
                }
            }
        }
        else
        {
            if (vector.at(2).valueToInt() == vector.at(1).valueToInt())
            {
                ++of_a_kind3;
                if (vector.at(2).valueToInt() == vector.at(0).valueToInt())
                {
                    ++of_a_kind3;
                }
            }
            else
            {
                if (vector.at(1).valueToInt() == vector.at(0).valueToInt())
                {
                    ++of_a_kind4;
                }
            }
        }
    }
    
    if (straight_ && flush_)
    {
        return straight_flush;
    }
    else if
        (
         of_a_kind1 == 4
         || of_a_kind2 == 4
         || of_a_kind3 == 4
         || of_a_kind4 == 4
         )
    {
        return four_of_a_kind;
    }
    else if
        (
         of_a_kind1 == 3
         || of_a_kind2 == 3
         || of_a_kind3 == 3
         || of_a_kind4 == 3
         )
    {
        if
            (
             of_a_kind1 == 2
             || of_a_kind2 == 2
             || of_a_kind3 == 2
             || of_a_kind4 == 2
             )
        {
            return full_house;
        }
        else
        {
            return three_of_a_kind;
        }
    }
    else if (flush_)
    {
        return is_flush;
    }
    else if (straight_)
    {
        return straight;
    }
    else if
        (
         of_a_kind1 == 2 &&
         (
          of_a_kind2 == 2
          || of_a_kind3 == 2
          || of_a_kind4 == 2
          )
         || of_a_kind2 == 2 &&
         (
          of_a_kind3 == 2
          || of_a_kind4 == 2
          )
         || of_a_kind3 == 2 && of_a_kind4 == 2
         )
    {
        return two_pair;
    }
    else if
        (
         of_a_kind1 == 2
         || of_a_kind2 == 2
         || of_a_kind3 == 2
         || of_a_kind4 == 2
         )
    {
        return one_pair;
    }
    else
    {
        return no_rank;
    }
    
}

//This uses the enumeration error_type 
//to print out helpful error messages
//upon various failures the program could run into
int error_handler(error_type failure_type)
{
    string msg_out = "";
    switch (failure_type){
        case 0:
            break;
        case -1:
            msg_out = "Incorrect card value";
            break;
        case -2:
            msg_out = "Failed to open file, please try again";
            break;
        case -3:
            msg_out = "Invalid Card passed to output stream";
            break;
        case -4:
            msg_out = "Could not open filestream";
            break;
        case -5:
            msg_out = "No arguments provided, please enter the name of the file to be read, and make sure that file is in the same directory as the executable file";
            break;
        case -6:
            msg_out = "No valid cards in input vector";
            break;
        case -7:
            msg_out = "An invalid card was passed to as_string in Hand.cpp";
            break;
        case -8:
            msg_out = "Only '-shuffle' was passed, please pass a filename with or without '-shuffle'";
            break;
        case -9:
            msg_out = "'-shuffle' was passed twice, please pass a filename with or without '-shuffle'";
            break;
        case -10:
            msg_out = "Two filenames were passed, please pass a filename with or without '-shuffle'";
            break;
        case -11:
            msg_out = "No cards to shuffle in the deck";
            break;
    }
    cout << "lab2" << " failed with error: " << failure_type << "\n" << msg_out << endl;
    return failure_type;
}

//Creates a buffer to get the file path
//a buffer is a WCHAR, and needs to be converted to an array of char *
//before being converted to a string.
//This gets us the exe filepath, so we truncate the string to end with the current directory
//string getFilePath()
//{
//    
//    
//    WCHAR buffer[_MAX_PATH];
//    GetModuleFileName(NULL, buffer, _MAX_PATH);
//    char ch[260];
//    char DefChar = ' ';
//    WideCharToMultiByte(CP_ACP, 0, buffer, -1, ch, 260, &DefChar, NULL);
//    std::string ss(ch);
//    return ss.substr(0, ss.find_last_of("\\/"));
//}