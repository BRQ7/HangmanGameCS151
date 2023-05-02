#ifndef FILE_NOT_FOUND_EXCEPTION_H
#define FILE_NOT_FOUND_EXCEPTION_H
#include <iostream>
#include "Exception.h"
using namespace std;

// File not found exception class that inherits from Exception 
class FileNotFoundException : public Exception
{
  public:
    // Constructor 
    FileNotFoundException();
};
#endif