// ----------------------------------------------------------------------------
/**
   File: maintest.cpp
  
   Author: lionel CHATAIN
   E-Mail: lionelchatain@gmail.com
  
   Description: 

   Date: 2017/10/31
*/  
// ----------------------------------------------------------------------------

#include "gmock/gmock.h"

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

