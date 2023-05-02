#include "Game.h"

// Checks if guess is in word and therefore correct, using recursion
bool containsChar(string word, char letter)
{
  int current_pos = word.size() - 1;
  // Word does not contain char, return false 
  if(current_pos < 0)
  {
    return false;
  }
  // Word contains char case insensitive, return true
  if(tolower(word.at(current_pos)) == letter)
  {
    return true;
  }
  // Try again using recursion
  return containsChar(word.substr(0, current_pos), letter);
}

// Constructor
Game::Game(string w)
{
  word = w;
  guesses = 0;
}

// Runs game 
void Game::runGame()
{
  bool wonGame;
  // Display hangman and word 
  hangman.display();
  displayWord();
  // Main loop 
  while(true)
  {
    // Get guess 
    char guess = getGuess();
    // Guess is not a letter 
    if(!isalpha(guess))
    {
      cout << "Please enter a valid letter!" << endl;
      continue;
    }
    // Guess has already been guessed 
    if(isAlreadyGuessed(guess))
    {
      cout << "Please enter a letter that you haven't already guessed!" << endl;
      continue;
    }
    // Increment guesses 
    guesses++;
    // Add new guessed letters to guessed lettters 
    guessed_letters.push_back(guess);
    // Correct guess
    if(containsChar(word, guess))
    {
      cout << "The guess '" << guess << "' was correct!" << endl;
      correct_letters.push_back(guess);
    }
    // Incorrect guess, make hangman take damage 
    else
    {
      cout << "The guess '" << guess << "' was incorrect!" << endl;
      hangman.takeDamage();
    }
    // Display hangman and word 
    hangman.display();
    displayWord();
    // Player guessed the entire word and player wins
    if(wordIsGuessed())
    {
      wonGame = true;
      break;
    }
    // Hangman is dead and player looses 
    else if(!hangman.isAlive())
    {
      wonGame = false;
      break;
    }
  }
  // Ends game based on player has won or lost 
  endGame(wonGame);
  
}

// Gets guessed letter case insensitive 
char Game::getGuess()
{
  char guess;
  cout << "Please enter your guess: ";
  cin >> guess;
  return tolower(guess);
}

// Check if letter is already guessed
bool Game::isAlreadyGuessed(char letter)
{
  // Iterate through each guessed letter 
  for(char guess : guessed_letters)
  {
    // Letter is already guessed
    if(guess == tolower(letter))
    {
      return true;
    }
  }
  // Letter is not already guessed 
  return false;
}

// Check if word is completely guessed
bool Game::wordIsGuessed()
{         
  // Iterate word by word 
  for(char c : word)
  {
    // Letter has not been guessed yet, return false 
    if(!isAlreadyGuessed(c))
    {
      return false;
    }
  }
  // Return true if word is completely guessed
  return true;
}

// Displays word with _ replacing non-guessed letters
void Game::displayWord()
{
  cout << "Word: ";
  // Iterate char by char through word 
  for(char c : word)
  {
   // Letter has already been guessed
   if(isAlreadyGuessed(c))
   {
     cout << c;
   }
   else
   {
     cout << "_";
   }
  }
  // Newline 
  cout << endl;
}
// Ends game
void Game::endGame(bool gameWon)
{
  // Newline 
  cout << endl;
  // Display word to the user 
  cout << "The word was " << word << endl;
  // Player won game 
  if(gameWon)
  {
    cout << "You won!" << endl;
    cout << "It took you " << guesses << " guesses!" << endl;
  }
  // Player lost game 
  else
  {
    cout << "You lost!" << endl;
  }
  // Newline
  cout << endl;
}
