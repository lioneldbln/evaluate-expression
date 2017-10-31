/**
   File: util.cpp
  
   Author: lionel CHATAIN
   E-Mail: lionelchatain@gmail.com
  
   Description: 

   Date: 2017/10/31
*/  
// ----------------------------------------------------------------------------

#include "util.h"

bool expreval::isNumberType(char c)
{
  if (c >= '0' && c <= '9')
    return true;

  return false;
}

bool expreval::isOperationType(char c)
{
  if (c == '+' || c == '-' || c == '*' || c == '/')
    return true;

  return false;
}

