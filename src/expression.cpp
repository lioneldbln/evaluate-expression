/**
   File: expression.cpp
  
   Author: lionel CHATAIN
   E-Mail: lionelchatain@gmail.com
  
   Description: 

   Date: 2017/10/31
*/  
// ----------------------------------------------------------------------------

#include "expression.h"

#include <exception>
#include <sstream>
#include "exception_exp.h"
#include "util.h"

void expreval::Expression::evaluate(int& result)
{
  if (str_exp.length() == 0)
  {
    return;
  }

  for (size_t i = 0; i < str_exp.length(); i++)
  {
    char token = str_exp.at(i);

    // skip whitespace
    if (token == ' ')
    {
      continue;
    }
    // current token is a number
    else if (expreval::isNumberType(token))
    {
      values.push(convertToNumber(i));
    }
    // current token is an operation
    else if (expreval::isOperationType(token))
    {
      while (!operations.empty() && operations.top() != '(' && operations.top() != ')')
      {
          performOperation();
      }
      operations.push(token);
    }
    // current token is an opening bracket
    else if (token == '(')
    {
      operations.push(token);
    }
    // current token is a closing bracket
    else if (token == ')')
    {
      bool openingBracketFound = false;
      while (!operations.empty())
      {
        if (operations.top() == '(')
        {
          openingBracketFound = true;
          break;
        }
        else
        {
          performOperation();
        }
      }
      if (openingBracketFound)
      {
        operations.pop();
      }
      else
      {
        throw(ill_formed_expression{ "Error: the expression is ill-formed" });
      }
    }
    // invalid character
    else
    {
      std::stringstream ss{};
      ss << "Error: the character '" << token << "'" << " is invalid";
      throw(non_valid_character{ss.str()});
    }
  }
  
  // perform operations to remaining values
  while (!operations.empty()) {
    performOperation();
  }

  if (values.size() > 1)
    throw(ill_formed_expression{"Error: the expression is ill-formed"});

  // top of 'values' contains the result
  result = values.top();
}

void expreval::Expression::performOperation()
{
  if (values.size() < 2 || operations.empty())
    throw(ill_formed_expression{"Error: the expression is ill-formed"});
    
  int rhs = values.top();
  values.pop();

  int lhs = values.top();
  values.pop();

  char op = operations.top();
  operations.pop();
  
  int result = 0;

  doArithmetic(lhs, rhs, op, result);

  values.push(result);
}

void expreval::Expression::doArithmetic(int lhs, int rhs, char op, int& result)
{
  if (op == '+')
  {
    result = lhs + rhs;
  }
  else if (op == '-')
  {
    result = lhs - rhs;
  }
  else if (op == '*')
  {
    result = lhs * rhs;
  }
  else if (op == '/')
  {
    if (rhs == 0)
      throw std::overflow_error("Error: Divide by zero exception");
    result = lhs / rhs;
  }
  else
  {
    std::stringstream ss{};
    ss << "Error: the character '" << op << "'" << " is invalid";
  }
}

int expreval::Expression::convertToNumber(size_t& i)
{
  std::string num{str_exp.at(i++)};
  while (i < str_exp.length() && isNumberType(str_exp.at(i)))
  {
    num += str_exp.at(i++);
  }
  i--;
  return std::stoi(num);
}

