//Jordan Deason Project 5

#include <iostream>
#include <string>
#include <cctype>
#include "Card.h"
#include "Deck.h"
using namespace std;

int main() {
    cout << "Welcome to Blind Man's Bluff" << endl << endl;
    //variable declarations
    bool play, invalid, guessedHigher;
    string response;
    // variables to keep track of win/loss/tie record and how many cards have been taken from the deck
    int winCount = 0, lossCount = 0, tieCount = 0, cardCount = 0;
    //calls default constructor
    Deck pileOfCards;
    Deck discardPile;
    //calls copy constructor
    Deck* copyPileOfCards = new Deck(pileOfCards);
    Deck* copyDiscardPile = new Deck(discardPile);

    //populating pileOfCards
    pileOfCards.populate();
    //randomizing deck
    pileOfCards.shuffle();

    //remains true unless user wants to stop playing
    play = true;

    while(play) {
        //assigns both card values randomly and subtracts a card from the deck each time
        Card user = pileOfCards.removeCard();
        Card computer = pileOfCards.removeCard();
        cardCount += 2; //keeps track of # of cards drawn so far; continues so as cardCount != 52

        cout << "Computer's card: " << computer.print() << endl;
        invalid = true;
        while(invalid) {
            cout << "Do you think your card is higher or lower? (H/L)" << endl;
            cin >> response; //takes in user input for guess
            if (toupper(response.at(0)) == 'H') {
                // continue playing
                guessedHigher = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'L') {
                // break out of while(play) loop
                guessedHigher = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }
        }

        // determine outcome
        //right
        if((user > computer && guessedHigher) || ( computer > user && !guessedHigher)) {          //checks if user guess is correct
            cout << "Great! You're right: " << endl;
            winCount++;
        }
        //wrong
        else if((computer > user  && guessedHigher) || (user > computer && !guessedHigher)) {     //checks if user guess is incorrect
            cout << "Sorry, you're wrong: " << endl;
            lossCount++;
        }
        //neither right nor wrong
        else {
            cout << "It's a tie:" << endl;
            tieCount++;
        }
        cout << "\tyour value is " << user.print() << endl;   //prints out your card

        //game ends if deck is empty
        if(cardCount == 52){
            cout << "Deck of cards is empty, thanks for playing!" << endl;
            cout << "Your record was " << winCount << "-" << lossCount << "-" << tieCount << " (W-L-T)" << endl;
            return 0;
        }

        // ask user to play again; continues until user says N
        invalid = true;
        while(invalid) {
            cout << "Play again? (Y/N)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'Y') { // continue playing
                //adds both cards to discardPile
                discardPile.addCard(user);
                discardPile.addCard(computer);
                play = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'N') {// stop playing; ends loop
                play = false;
                invalid = false;
            }
            // in the case of an invalid response
            else {
                cout << "Invalid response." << endl;
                invalid = true;
            }
        }
    }
    // output game stats
    cout << "Thank you for playing!" << endl;
    cout << "Your record was " << winCount << "-" << lossCount << "-" << tieCount << " (W-L-T)" << endl;


    discardPile = pileOfCards;
    return 0;
}