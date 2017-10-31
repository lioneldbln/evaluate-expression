/**
   File: exception_exp.h
  
   Author: lionel CHATAIN
   E-Mail: lionelchatain@gmail.com
  
   Description: 

   Date: 2017/10/31
*/  
// ----------------------------------------------------------------------------

#pragma once

#include <exception>

class non_valid_character : public std::exception {
private:
  std::string message;

public:
  non_valid_character(const std::string &message) : message(message) {}
  ~non_valid_character() = default;
  non_valid_character(const non_valid_character&) = default;
  non_valid_character& operator=(const non_valid_character&) = default;
  non_valid_character(non_valid_character&&) = default;
  non_valid_character& operator=(non_valid_character&&) = default;

  const char* what() const noexcept override { return message.c_str(); }
};

class missing_bracket : public std::exception {
private:
  std::string message;

public:
  missing_bracket(const std::string &message) : message(message) {}
  ~missing_bracket() = default;
  missing_bracket(const missing_bracket&) = default;
  missing_bracket& operator=(const missing_bracket&) = default;
  missing_bracket(missing_bracket&&) = default;
  missing_bracket& operator=(missing_bracket&&) = default;

  const char* what() const noexcept override { return message.c_str(); }
};

class ill_formed_expression : public std::exception {
private:
  std::string message;

public:
  ill_formed_expression(const std::string &message) : message(message) {}
  ~ill_formed_expression() = default;
  ill_formed_expression(const ill_formed_expression&) = default;
  ill_formed_expression& operator=(const ill_formed_expression&) = default;
  ill_formed_expression(ill_formed_expression&&) = default;
  ill_formed_expression& operator=(ill_formed_expression&&) = default;

  const char* what() const noexcept override { return message.c_str(); }
};

