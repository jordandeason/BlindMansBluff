#include "Card.h"
using namespace std;

//default constructor
Card::Card(){
}

//copy constructor
Card::Card(int rank, int suit) {
    this-> rank = rank;
    this-> suit = suit;
}

//overload operator
bool Card::operator >(Card computer) {
    if(rank != computer.rank){
        return rank > computer.rank;
    }
    else{
        return suit >computer.suit;
    }
}

//printing rank and suit
string Card::print() {
    return ranks[rank] + " of " + suits[suit];
}