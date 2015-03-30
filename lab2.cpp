//		David McDonnel				//
//		WUID #: 420325				//
//		email : dmcdonnel@wustl.edu	//
//		3/4/2015					//
//		CSE 332: lab 2				//
//////////////////////////////////////
#include "stdafx.h"
#include <vector>
#include <string>
#include <algorithm>
#include "Hand.h"
class Hand;
#include "Deck.h"
class Deck;
#include "card.h"
using namespace std;

void printHands(vector<Hand> &h){
	vector<Hand>::iterator it = h.begin();
	vector<Hand>::iterator itEnd = h.end();
	int count = 1;
	//for (it; it != itEnd;){
	//		cout << "Hand" << count << ": " << endl;
	//		cout << it->as_string() << endl;
	//		/*try{
	//			it->as_string();
	//		}
	//		catch (string s){
	//			cout << s << endl;
	//		}
	//		catch (...){
	//			error_handler(Invalid_Card_as_string);
	//		}*/
	//		++count;
	//	}
}

void dostuff(Deck &d){
	cout << "hi" << endl;
	vector<Hand> hands;
	for (int i = 0; i < players; ++i)
	{
		hands.push_back(Hand::Hand());
	}
	for (int i = 0; i < cards_dealt; ++i){
		hands[i % 9] << d;
	}
	cout << "Deck: " << endl;
	cout << d;
	
	printHands(hands);
	std::sort(hands.begin(), hands.end());
	printHands(hands);
	sort(hands.begin(), hands.end(), poker_rank);
	printHands(hands);
}


int main(int argc, char * argv[])
{
	bool b = false;
	if (argc == 2)
	{
		if (argv[1] == "-shuffle")
		{
			error_handler(Only_shuffle);
		}
		else
		{
			Deck d = Deck::Deck(argv[1]);
			dostuff(d);
		}
	}
	else if (argc == 3)
	{
		if (argv[1] == "-shuffle" && argv[2] == "-shuffle")
		{
			error_handler(Two_Shuffles);
		}
		else
		{
			if (argv[1] == "-shuffle" || argv[2] == "-shuffle")
			{
				if (argv[1] == "-shuffle")
				{
					Deck d = Deck::Deck(argv[2]);
					d.shuffle();
					dostuff(d);
				}
				else
				{
					Deck d = Deck::Deck(argv[1]);
					d.shuffle();
					dostuff(d);
				}
			}
			else
			{
				error_handler(Two_Files);
			}
		}
	}
	return 0;
}