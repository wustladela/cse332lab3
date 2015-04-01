//		David McDonnel				//
//		WUID #: 420325				//
//		email : dmcdonnel@wustl.edu	//
//		3/4/2015					//
//		CSE 332: lab 2				//
//////////////////////////////////////

//#include "stdafx.h"
#include "card.h"
#include <string>
#include <iostream>
using namespace std;

//default and standard constructors
Card::Card(){};
Card::Card(char s, string v){
    suit = s;
    value = v;
}

//This just returns the string value of a card
string Card::returnCard()
{
    return suitCheck(suit) + valueCheck(value);
}

int Card::suitToInt(char suit_)
{
    return suitToIntHelp(suit_);
}

int Card::valueToInt(const string value_)
{
    return valueToIntHelp(value_.c_str());
}

int const Card::suitToInt() const
{
    return suitToIntHelp(suit);
}

int const Card::valueToInt() const
{
    return valueToIntHelp(value);
}
//This applies the bool operator to Card
const bool operator< (const Card &card1, const Card &card2)
{
    if (card1.valueToInt() < card2.valueToInt())
    {
        return true;
        cout << &card1.value << &card1.suit << " < " << &card2.value << &card2.suit << endl;
    }
    else
    {
        if (card1.valueToInt() > card2.valueToInt())
        {
            return false;
            cout << &card1.value << &card1.suit << " > " << &card2.value << &card2.suit << endl;
        }else{
            if (card1.suitToInt() < card2.suitToInt())
            {
                return true;
                cout << &card1.value << &card1.suit << " < " << &card2.value << &card2.suit << endl;
            }
            else
            {
                return false;
                cout << &card1.value << &card1.suit << " > " << &card2.value << &card2.suit << endl;
            }
        }
    }
}

//This transforms the input substring (suit) into the appropriate format for output
string Card::suitCheck(char suit)
{
    switch (suit)
    {
        case C:
            return "C";
            break;
        case c:
            return "C";
            break;
        case D:
            return "D";
            break;
        case d:
            return "D";
            break;
        case H:
            return "H";
            break;
        case h:
            return "H";
            break;
        case S:
            return "S";
            break;
        case s:
            return "S";
            break;
        default:
            return "false";
            break;
    }
}

//This transforms the input substring (value) into the appropriate format for output
string  Card::valueCheck(string value)
{
    switch (suit)
    {
        case two:
            return "two";
            break;
        case three:
            return "three";
            break;
        case four:
            return "four";
            break;
        case five:
            return "five";
            break;
        case six:
            return "six";
            break;
        case seven:
            return "seven";
            break;
        case eight:
            return "eight";
            break;
        case nine:
            return "nine";
            break;
        case ten:
            return "ten";
            break;
        case J:
            return "jack";
            break;
        case j:
            return "jack";
            break;
        case Q:
            return "queen";
            break;
        case q:
            return "queen";
            break;
        case K:
            return "king";
            break;
        case k:
            return "king";
            break;
        case A:
            return "ace";
            break;
        case a:
            return "ace";
            break;
        default:
            return "false";
    }
}

int const Card::suitToIntHelp(char suit_) const
{
    if (suit_ == 'C')
    {
        return C;
    }
    else if (suit_ == 'c')
    {
        return C;
    }
    else if (suit_ == 'D')
    {
        return D;
    }
    else if (suit_ == 'd')
    {
        return D;
    }
    else if (suit_ == 'H')
    {
        return H;
    }
    else if (suit_ == 'h')
    {
        return H;
    }
    else if (suit_ == 'S')
    {
        return S;
    }
    else if (suit_ == 's')
    {
        return S;
    }
    else
    {
        return -1;
    }
}


int const Card::valueToIntHelp(string value_) const
{
    if (value_ == "2")
    {
        return two;
    }
    else if (value_ == "3")
    {
        return three;
    }
    else if (value_ == "4")
    {
        return four;
    }
    else if (value_ == "5")
    {
        return five;
    }
    else if (value_ == "6")
    {
        return six;
    }
    else if (value_ == "7")
    {
        return seven;
    }
    else if (value_ == "8")
    {
        return eight;
    }
    else if (value_ == "9")
    {
        return nine;
    }
    else if (value_ == "10")
    {
        return ten;
    }
    else if (value_ == "J")
    {
        return J;
    }
    else if (value_ == "Q")
    {
        return Q;
    }
    else if (value_ == "K")
    {
        return K;
    }
    else if (value_ == "A")
    {
        return A;
    }
    else if (value_ == "j")
    {
        return J;
    }
    else if (value_ == "q")
    {
        return Q;
    }
    else if (value_ == "k")
    {
        return K;
    }
    else if (value_ == "a")
    {
        return A;
    }
    else
    {
        return -1;
    }
    
}