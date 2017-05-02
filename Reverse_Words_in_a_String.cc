#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
	bool checkCondition(int wordPos,int length){
		if(wordPos < length)
			return true;
		else
			return false;
	}
    string reverseWords(string &s) {
        int startPos = 0;
        int wordPos = 0;
        int ansPos = 0;
		int length = s.size();
		while(checkCondition(wordPos,length)){
			while(checkCondition(wordPos,length) && s[wordPos] == ' ')
				wordPos++;
			if(checkCondition(wordPos,length) && ansPos > 0)
				s[ansPos++] = ' ';
			startPos = ansPos;
			while(checkCondition(wordPos,length) && s[wordPos] != ' ')
				s[ansPos++] = s[wordPos++];
			reverse(s.begin()+startPos,s.begin()+ansPos);
        }
        s.resize(ansPos);
		reverse(s.begin(), s.end());
		return s;
    }
};

TEST(reverseWords, spacestring) {
  string s ="   ";
  string ans = "";
  EXPECT_EQ(Solution().reverseWords(s),ans);
}

TEST(reverseWords, Firstspacestring) {
  string s =" a";
  string ans = "a";
  EXPECT_EQ(Solution().reverseWords(s),ans);
}

TEST(reverseWords, Lastspacestring) {
  string s ="a ";
  string ans = "a";
  EXPECT_EQ(Solution().reverseWords(s),ans);
}

TEST(reverseWords, longstring) {
  string s ="the sky    is   blue";
  string ans = "blue is sky the";
  EXPECT_EQ(Solution().reverseWords(s),ans);
}

int main(int argc, char** argv) {
  // Prints elapsed time by default.
  //testing::GTEST_FLAG(print_time) = true;

  // This allows the user to override the flag on the command line.
  testing::InitGoogleTest(&argc, argv);
  
  RUN_ALL_TESTS();
  system("pause");
  return 0;
}
