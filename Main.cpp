// This is Partial Output, Not the Final One!
#include <iostream>
#include <string>
#include "Stacks.h"
#include "LinkedList.h"

using namespace std;

void initializeGame(string& secretWord, int& maxGuesses);
void displayGameState(const string& guessedWord, int incorrectGuesses, const Stack& incorrectLetters);
bool checkGuess(char guess, const string& secretWord, string& guessedWord, Stack& incorrectLetters);

int main() 
{
    string secretWord;
    string guessedWord; 
    int maxGuesses = 6;
    int incorrectGuesses = 0;
    
    Stack incorrectLetters;
    initializeGame(secretWord, maxGuesses);
    
    
    guessedWord.assign(secretWord.length(), '_');

    cout << "Welcome to Hangman!" << endl;
    
    while (incorrectGuesses < maxGuesses && guessedWord.find('_') != string::npos) {
        
        
        displayGameState(guessedWord, incorrectGuesses, incorrectLetters);

        char guess;
        cout << "\nEnter your letter guess: ";
        cin >> guess;
    
        guess = toupper(guess); 
       
        if (!checkGuess(guess, secretWord, guessedWord, incorrectLetters)) 
        {   incorrectGuesses++;
            cout << "Incorrect guess!" << endl;
        } else {
            if (guessedWord.find(guess) != string::npos) {
                cout << "Correct guess!" << endl;
            }
        }
    }

    cout << "\n--- GAME OVER ---" << endl; 
    if (guessedWord.find('_') == string::npos) {
        cout << "CONGRATULATIONS! You guessed the word: " << secretWord << endl;
    } else {
        displayGameState(guessedWord, incorrectGuesses, incorrectLetters); 
        cout << "YOU LOST! The secret word was: " << secretWord << endl;
    }
    
    return 0;
}