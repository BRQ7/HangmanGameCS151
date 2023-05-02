#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include "Hangman.h"
using namespace std;

// Game class 
class Game
{
  private:
    // Hangman 
    Hangman hangman;
    // Game word 
    string word;
    // Guessed letters
    vector<char> guessed_letters;
    // Correct letters
    vector<char> correct_letters;
    // Number of guesses
    int guesses;
    // Gets guessed letter case insensitive 
    char getGuess();
    // Check if letter is already guessed
    bool isAlreadyGuessed(char);
    // Check if word is completely guessed
    bool wordIsGuessed();
    // Displays word with _ replacing non-guessed letters
    void displayWord();
    // Ends game
    void endGame(bool);
  public:
    // Constructor 
    Game(string);
    // Runs game 
    void runGame();
};
#endif