/* HangmanGame.cpp - A hangman game that allows the user to customize the words for the game in a text file 
   * Author:     Brandon Quandt
   * Module:     Final
   * Project:    Final Project
   * Problem Statement : Create a classic hangman game that allows the user to customize the games words list in a text file Words.txt, have the game also explain how to play the game along with having a visual hangman in ASCII for the player to visualize how much health the hangman has left and display how many guesses it took a player to win if they did win the game
   * Algorithim :
   * 1. Create a hangman class that represents a hangman that has health and is displayed based upon the health
   * 2. Create a game class that takes in a word and runs the game and has a hangman, getting user input, use vectors to stored guessed letters and correct letters to ensure if user enters an already guessed letter and to check for win scenario
   * 3. Player looses game if hangman looses all parts before entire word is guessed, and player wins game if the player guesses all letters of the word, display number of guesses to player if they win
   * 4. Use a recursive method (meets item D requirement) containsChar that recursively checks if a string contains a char 
   * 5. Create a generic exception class that contains an error message along with exception child classes FileNotFoundException and BoundsException (meets item E requirement and item A requirement)
   * 6. In main, enable true randomness and open a words file throwing an exception if it does not work (meeting item C requirement)
   * 7. Read the file of words and insert into the vector of strings catching any exceptions 
   * 8. In main also print hangman logo, catch exception if user input for menu option is out of bounds, and allow user to play new game, view how to play, or quit game
*/
#include <iostream>
#include <fstream>
#include <vector>
#include "BoundsException.h"
#include "FileNotFoundException.h"
#include "Game.h"
using namespace std;

// Display menu options
void displayMenuOptions();
// Get integer input between two bounds, otherwise throws a bounds exception
int getInputBounds(int, int);
// Returns a vector of words from a file 
vector<string> getWords(ifstream &);

int main()
{
  // Enable true randomness
  srand(time(0));
  // Open input file, Words.txt, that contains words to use for the hangman game
  const string WORDS_FILE_NAME = "Words.txt"; 
  ifstream words_file(WORDS_FILE_NAME, ios::in);
  try
  {
    // Check if file is valid, otherwise throw FileNotFoundException 
    if(!words_file)
    {
      throw FileNotFoundException();
    }
  }  
  // Catch FileNotFoundException 
  catch(const FileNotFoundException &exception)
  {
    // Print error message and exit 
    cerr << exception.getErrorMessage() << endl;  
    exit(1);
  }
  // Obtain a vector of words from the text file
  vector<string> words;
  try 
  {
    words = getWords(words_file);
  }
  // Catch exception 
  catch(const Exception &exception)
  {
    cerr << exception.getErrorMessage() << endl;
    exit(1);
  }
  // Display hangman logo
  cout << "------  \n"
          "|    |  \n"
          "|   \\0/\n"
          "|    |  \n"
          "|   / \\\n"
          "|       \n",
  // Display welcome message
  cout << "Welcome to Hangman!" << endl;
  // Main menu
  while(true) 
  {
    // Display menu options
    displayMenuOptions();
    // Prompt user for menu option
    int option; 
    cout << "Please enter a menu option: ";  
    // Successfuly get a menu option from the player
    try 
    {
      option = getInputBounds(1, 3);
    }
    // Catch bounds exception if out of range 
    catch(const BoundsException &exception)
    {
      cout << "Entered number must be an option!" << endl;
    }
    // Start and run new game if option 1 is selected 
    if(option == 1)
    {
      cout << "Starting new game!" << endl;
      cout << endl;
      // Starts game with random chosen word 
      Game game(words.at(rand() % words.size()));
      game.runGame();
    }
    // Display how to play game 
    if(option == 2)
    {
      cout << "This version of hangman is a single player game in which the player's goal is to guess all the letters of a random word (randomly chosen from the Words.txt file). Every incorrect guess results in the hangman loosing a part, if he looses all parts then the game is lost. If the player guesses all the letters to the word before he looses his parts then the game is won. Good luck and have fun!" << endl;
      cout << endl;
    }
    // Quit program if 3rd option is selected
    if(option == 3)
    {
      break;
    }
  }
  // End user with a thank you message 
  cout << "Thank you for playing!" << endl;
}

// Display menu options
void displayMenuOptions()
{
  cout << "1. Play New Game" << endl;
  cout << "2. How To Play" << endl;
  cout << "3. Quit Game" << endl;
}

// Get integer input between two bounds, otherwise throws a bounds exception
int getInputBounds(int lower, int upper)
{
  int number;
  cin >> number;
  // Ensure integer is within bounds, otherwise throw a BoundsException()
  if(number < lower || number > upper)
  {
    throw BoundsException();
  }
  return number;
}

// Returns a vector of words from a file 
vector<string> getWords(ifstream & input_file)
{
  // A vector of words to use for the hangman game
  vector<string> words;
  // Read words file word by word and adds to end of words vector 
  string current_word;
  while(input_file >> current_word)
  {
    // Iterate through word character by character 
    for(char c : current_word)
    {
      // Throw a generic exception if a word contains a non letter character 
      if(!isalpha(c))
      {
         throw Exception("Error: A word (" + current_word + ") contains a character that is not a letter!");
      }
    }
    // Add current word to the vector of words 
    words.push_back(current_word);
  }
  // If file is empty, throw a generic exception 
  if(words.size() == 0)
  {
    throw Exception("Error: Words file must contain at least one word!");
  }
  // Return vector of words
  return words;
}