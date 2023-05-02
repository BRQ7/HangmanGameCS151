#ifndef BOUNDS_EXCEPTION_H
#define BOUNDS_EXCEPTION_H
#include <iostream>
#include "Exception.h"
using namespace std;

// Bounds exception class that inherits from Exception 
class BoundsException : public Exception
{
  public:
    // Constructor 
    BoundsException();
};
#endif