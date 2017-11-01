/**
   File: utiltests.cpp
  
   Author: lionel CHATAIN
   E-Mail: lionelchatain@gmail.com
  
   Description: 

   Date: 2017/10/31
*/  
// ----------------------------------------------------------------------------

#include "util.h"

#include "gmock/gmock.h"

TEST(UtilTest, charZeroIsNumber)
{
  ASSERT_THAT(expreval::isCharacterNumber('0'), testing::Eq(true));
}

TEST(UtilTest, charNineIsNumber)
{
  ASSERT_THAT(expreval::isCharacterNumber('9'), testing::Eq(true));
}

TEST(UtilTest, charTIsNotNumber)
{
  ASSERT_THAT(expreval::isCharacterNumber('T'), testing::Eq(false));
}

TEST(UtilTest, charPlusIsOperator)
{
  ASSERT_THAT(expreval::isCharacterOperator('+'), testing::Eq(true));
}

TEST(UtilTest, charMinusIsOperator)
{
  ASSERT_THAT(expreval::isCharacterOperator('-'), testing::Eq(true));
}

TEST(UtilTest, charStarIsOperator)
{
  ASSERT_THAT(expreval::isCharacterOperator('*'), testing::Eq(true));
}

TEST(UtilTest, charSlashIsOperator)
{
  ASSERT_THAT(expreval::isCharacterOperator('/'), testing::Eq(true));
}

TEST(UtilTest, charCaretIsNotOperator)
{
  ASSERT_THAT(expreval::isCharacterOperator('^'), testing::Eq(false));
}
