#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>
using namespace std;

// Base exception class 
class Exception
{
  private:
    // Error message
    string error_message;
  public:
    // Constructor 
    Exception(string);
    // Gets error message 
    string getErrorMessage() const;
};
#endif