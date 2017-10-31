/**
   File: expression.h
  
   Author: lionel CHATAIN
   E-Mail: lionelchatain@gmail.com
  
   Description: 

   Date: 2017/10/31
*/  
// ----------------------------------------------------------------------------

#pragma once

#include <string>
#include <stack>
#include <exception>
#include <sstream>
#include "exception_exp.h"
#include "util.h"

namespace expreval {
  template<typename T>
  class Expression {
  private:
    std::string str_exp;
    std::stack<T> values;
    std::stack<char> operations;
    
    void performOperation();
    void doArithmetic(T, T, char, T&);
    T convertToNumber(size_t&);

  public:
    Expression(const char* str_exp) : str_exp{str_exp}, values{}, operations{} {}
    ~Expression() = default;
    Expression(const Expression&) = default;
    Expression& operator=(const Expression&) = default;
    Expression(Expression&&) = default;
    Expression& operator=(Expression&&) = default;

    void evaluate(T&);
  };
}

template<typename T>
void expreval::Expression<T>::evaluate(T& result)
{
  if (str_exp.length() == 0)
  {
    return;
  }

  for (size_t i = 0; i < str_exp.length(); i++)
  {
    char token = str_exp[i];

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
        throw(ill_formed_expression{ "the expression is ill-formed" });
      }
    }
    // invalid character
    else
    {
      std::stringstream ss{};
      ss << "the character '" << token << "'" << " is invalid";
      throw(non_valid_character{ss.str()});
    }
  }
  
  // perform operations to remaining values
  while (!operations.empty()) {
    performOperation();
  }

  if (values.size() > 1)
    throw(ill_formed_expression{"the expression is ill-formed"});

  // top of 'values' contains the result
  result = values.top();
}

template<typename T>
void expreval::Expression<T>::performOperation()
{
  if (values.size() < 2 || operations.empty())
    throw(ill_formed_expression{"the expression is ill-formed"});
    
  T rhs = values.top();
  values.pop();

  T lhs = values.top();
  values.pop();

  char op = operations.top();
  operations.pop();
  
  T result = 0;

  doArithmetic(lhs, rhs, op, result);

  values.push(result);
}

template<typename T>
void expreval::Expression<T>::doArithmetic(T lhs, T rhs, char op, T& result)
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
      throw std::overflow_error("Divide by zero exception");
    result = lhs / rhs;
  }
  else
  {
    std::stringstream ss{};
    ss << "the character '" << op << "'" << " is invalid";
    throw(non_valid_character{ss.str()});
  }
}

template<typename T>
T expreval::Expression<T>::convertToNumber(size_t& i)
{
  T num{};
  while (i < str_exp.length() && isNumberType(str_exp[i]))
  {
    num = num*10+(str_exp[i++]-'0');
  }
  i--;
  return num;
}

