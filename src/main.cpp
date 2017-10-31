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
#include "expression.h"

bool evaluate(const char* expression, int& result);

int main(int argc, char* argv[])
{
  while (1)
  {
    std::string expression{};
    std::cout << "Please enter an expression to evaluate ('q' to quit):" << std::endl; 
    std::getline(std::cin, expression);
    int result = 0;
    if (expression.empty())
    {
      std::cerr << "Error: no expression found" << std::endl;
    }
    else if (expression == "q")
    {
      break;
    }
    else
    {
      if (evaluate(expression.c_str(), result))
      {
        std::cout << "result: " << result << std::endl;
      }
    }
  }
  return 0;
}

bool evaluate(const char* expression, int& result)
{
  try
  {
    expreval::Expression exp{expression};
    exp.evaluate(result);
    return true;
  }
  catch(std::exception& ex) {
    std::cerr << ex.what() << std::endl;
  }
  catch(...)
  {
    std::cerr << "Error: Unknown exception" << std::endl;
  }
  return false;
}

