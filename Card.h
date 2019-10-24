#ifndef BLINDMANSBLUFF_CARD_H
#define BLINDMANSBLUFF_CARD_H
#include <string>
using namespace std;

//ranks ordered ace-low and queen-high
const string ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "King", "Queen"};
//suits ordered alphabetically
const string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

class Card {
//public functions
public:
    Card();
    Card(int rank, int suits);
    //true if user wins
    bool operator > (Card computer);
    string print();

//private variables
private:
    int rank;
    int suit;
};

#endif //BLINDMANSBLUFF_CARD_H