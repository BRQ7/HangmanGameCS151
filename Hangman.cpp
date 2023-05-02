#include "Hangman.h"

// Hangman starting health 
const int Hangman::STARTING_HEALTH = 6;
// Hangman states represented as an array of ASCII strings
const string Hangman::states[STARTING_HEALTH + 1] = 
{
// Hangman at max health
"------  \n"
"|    |  \n"
"|   \\0/\n"
"|    |  \n"
"|   / \\\n"
"|       \n", 
// Hangman lost right leg 
"------  \n"
"|    |  \n"
"|   \\0/\n"
"|    |  \n"
"|   /   \n"
"|       \n",
// Hangman lost left leg
"------  \n"
"|    |  \n"
"|   \\0/\n"
"|    |  \n"
"|       \n"
"|       \n",
// Hangman lost right arm
"------  \n"
"|    |  \n"
"|   \\0 \n"
"|    |  \n"
"|       \n"
"|       \n",
// Hangman lost left arm
"------  \n"
"|    |  \n"
"|    0  \n"
"|    |  \n"
"|       \n"
"|       \n",
// Hangman lost torso
"------  \n"
"|    |  \n"
"|    0  \n"
"|       \n"
"|       \n"
"|       \n",  
// Hangman dead
"------  \n"
"|    |  \n"
"|       \n"
"|       \n"
"|       \n"
"|       \n"
};

// Constructor 
Hangman::Hangman()
{
  health = STARTING_HEALTH;
}

// Displays hangman based on health
void Hangman::display()
{
  cout << states[STARTING_HEALTH - health] << endl;
}

// Decrements hangman health by 1 
void Hangman::takeDamage()
{
  health--;
}

// Checks if hangman is still alive
bool Hangman::isAlive()
{
  return health > 0;
}