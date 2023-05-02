#include "Exception.h"

// Constructor 
Exception::Exception(string e)
{
  error_message = e;
}

// Gets error message
string Exception::getErrorMessage() const
{
  return error_message;
}