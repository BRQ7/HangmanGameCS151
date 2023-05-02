#ifndef HANGMAN_H
#define HANGMAN_H
#include <iostream>
using namespace std;

// Hangman class
class Hangman
{
  private:
    // Hangman starting health 
    const static int STARTING_HEALTH;
    // Hangman states 
    const static string states[];
    // Hangman health 
    int health;
  public:
    // Constructor 
    Hangman();
    // Displays hangman based on health 
    void display();
    // Decrements hangman health by 1 
    void takeDamage();
    // Checks if hangman is still alive
    bool isAlive();
};

#endif