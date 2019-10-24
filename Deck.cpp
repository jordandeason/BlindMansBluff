#include "Deck.h"
#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;
// default constructor; creates array of cards size 52
Deck::Deck() {
    cout << "Constructor called." << endl;
    cards = new Card[52];
    arraySize = 52;
    cardsLeft = 0;
}

// copy constructor
Deck :: Deck (const Deck& copyDeck ){
    cout << "Copy Constructor called." << endl;
    arraySize = copyDeck.arraySize;
    cardsLeft = copyDeck.cardsLeft;
    cards = new Card[arraySize];

    for(int i = 0; i < arraySize; i++){
        cards[i] = copyDeck.cards[i];
    }
}

// destructor
Deck::~Deck() {
    cout << "Destructor called." << endl;
    delete [] cards;      //deletes array of cards
}

Deck &Deck::operator=(Deck assignment) {  //copy assignment operator
    cout<<"Assignment operator called"<<endl;
    //built in swap
    swap(cards, assignment.cards);
    arraySize = assignment.arraySize;
    cardsLeft = assignment.cardsLeft;
    return *this;
}

//populating the deck with cards
void Deck::populate() {
    //two levels because suits and ranks
    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 4; j++){
            addCard(Card(i,j));

        }
    }
}

//shuffle deck
void Deck::shuffle(){
    //randomize number each time
    srand(time(0));
    for(int i = 0; i < pow(cardsLeft, 2); i++){
        //swap cards in deck
        swap(cards[rand() % 52],cards[rand() % 52]);

    }
}

//adding cards to decks
bool Deck::addCard(Card newCard) {
    if(cardsLeft < arraySize){
        cards[cardsLeft++] = newCard;
    }
    return false;
}

//removing cards from the deck
Card Deck::removeCard() {
    return cards[--cardsLeft];
}