// ----------------------------------------------------------------------------
/**
   File: main.cpp
  
   Author: lionel CHATAIN
   E-Mail: lionelchatain@gmail.com
  
   Description: 

   Date: 2017/10/31
*/  
// ----------------------------------------------------------------------------

#include <iostream>
#include <exception>

int main(int argc, char* argv[])
{
  try
  {
    std::cout << "Hello World!" << std::endl;
  }    
  catch(...)
  {
    std::cerr << "Unknown exception" << std::endl;
    std::cerr << "!!FAILURE!!" << std::endl;
  }

  return 0;
}

