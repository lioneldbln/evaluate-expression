/**
   File: expressiontests.cpp
  
   Author: lionel CHATAIN
   E-Mail: lionelchatain@gmail.com
  
   Description: 

   Date: 2017/10/31
*/  
// ----------------------------------------------------------------------------

#include "expression.h"

#include "gmock/gmock.h"
#include <exception>
#include "exception_exp.h"

TEST(ExpressionTest, EvaluateOneOperationWithOneDigitNumbers)
{
  expreval::Expression<int> expression("3 + 1");
  int result = 0;
  expression.evaluate(result);
  ASSERT_THAT(result, testing::Eq(4));
}

TEST(ExpressionTest, EvaluateTwoOperationsWithOneDigitNumbers)
{
  expreval::Expression<int> expression("3 + 1 * 4");
  int result = 0;
  expression.evaluate(result);
  ASSERT_THAT(result, testing::Eq(16));
}

TEST(ExpressionTest, EvaluateTwoOperationsWithMoreThanOneDigitsNumbers)
{
  expreval::Expression<int> expression("11 * 100 + 25");
  int result = 0;
  expression.evaluate(result);
  ASSERT_THAT(result, testing::Eq(1125));
}

TEST(ExpressionTest, EvaluateOperationsGivingNegativeResult)
{
  expreval::Expression<int> expression("4 - 10 / 2");
  int result = 0;
  expression.evaluate(result);
  ASSERT_THAT(result, testing::Eq(-3));
}

TEST(ExpressionTest, EvaluateOneBracketCoupleInFirstPosition)
{
  expreval::Expression<int> expression("(10 + 30) * 21");
  int result = 0;
  expression.evaluate(result);
  ASSERT_THAT(result, testing::Eq(840));
}

TEST(ExpressionTest, EvaluateOneBracketCoupleInLastPosition)
{
  expreval::Expression<int> expression("6 + (4 / 2)");
  int result = 0;
  expression.evaluate(result);
  ASSERT_THAT(result, testing::Eq(8));
}

TEST(ExpressionTest, EvaluateMutipleBracketsCouple)
{
  expreval::Expression<int> expression("(1 + 2) * (5 + 10)");
  int result = 0;
  expression.evaluate(result);
  ASSERT_THAT(result, testing::Eq(45));
}

TEST(ExpressionTest, EvaluateNestedBracketsCouple)
{
  expreval::Expression<int> expression("2 + ((1 + 2) * (5 + 10))");
  int result = 0;
  expression.evaluate(result);
  ASSERT_THAT(result, testing::Eq(47));
}

TEST(ExpressionTest, EvaluateExpressionWithMissingBracket)
{
  expreval::Expression<int> expression("(1 + (12 * 2)");
  int result = 0;
  ASSERT_THROW(expression.evaluate(result), ill_formed_expression);
}

TEST(ExpressionTest, EvaluateExpressionWithNumberWithoutOperatorOnLeft)
{
  expreval::Expression<int> expression("2 + ((1 + 2) * (5 + 10))20");
  int result = 0;
  ASSERT_THROW(expression.evaluate(result), ill_formed_expression);
}

TEST(ExpressionTest, EvaluateExpressionWithNumberWithoutOperatorOnRight)
{
  expreval::Expression<int> expression("3 (3 / 1)");
  int result = 0;
  ASSERT_THROW(expression.evaluate(result), ill_formed_expression);
}

TEST(ExpressionTest, EvaluateExpressionWithTwoConsecutiveOperators)
{
  expreval::Expression<int> expression("3 + / 1");
  int result = 0;
  ASSERT_THROW(expression.evaluate(result), ill_formed_expression);
}

TEST(ExpressionTest, EvaluateExpressionWithiDivisionByZero)
{
  expreval::Expression<int> expression("4 - 3 / 0");
  int result = 0;
  ASSERT_THROW(expression.evaluate(result), std::overflow_error);
}

TEST(ExpressionTest, EvaluateExpressionWithOnlyOneClosingBracketAtTheEnd)
{
	expreval::Expression<int> expression("1 + 3)");
	int result = 0;
	ASSERT_THROW(expression.evaluate(result), ill_formed_expression);
}

TEST(ExpressionTest, EvaluateExpressionWithOnlyOneOpeningBracketAtTheBeginning)
{
  expreval::Expression<int> expression("(1 + 3");
  int result = 0;
  ASSERT_THROW(expression.evaluate(result), ill_formed_expression);
}

TEST(ExpressionTest, EvaluateExpressionWithInvalidCharacter)
{
  expreval::Expression<int> expression("(1 + 3) ^ 8");
  int result = 0;
  ASSERT_THROW(expression.evaluate(result), non_valid_character);
}

TEST(ExpressionTest, EvaluateExpressionGivingFloatResult)
{
  expreval::Expression<float> expression("5 / 2");
  float result = 0;
  expression.evaluate(result);
  ASSERT_THAT(result, testing::Eq(2.5));
}

