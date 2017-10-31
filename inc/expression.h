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

namespace expreval {
  class Expression {
  private:
    std::string str_exp;
    std::stack<int> values;
    std::stack<char> operations;

    void performOperation();
    void doArithmetic(int, int, char, int&);
    int convertToNumber(size_t&);

  public:
    Expression(const char* str_exp) : str_exp{str_exp}, values{}, operations{} {}
    ~Expression() = default;
    Expression(const Expression&) = default;
    Expression& operator=(const Expression&) = default;
    Expression(Expression&&) = default;
    Expression& operator=(Expression&&) = default;

    void evaluate(int&);
  };
}

