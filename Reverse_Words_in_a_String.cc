#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    string reverseWords(string &s) {
        reverse(s.begin(),s.end());
        int startPos = 0;
        int length = 0;
        int realPos = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                if(length){
                    reverse(s.begin()+startPos,s.begin()+startPos+length);
                    length = 0;
                    s[realPos++] = s[i];
                }
            }
            else{
                if(length == 0)
                    startPos = realPos;
                s[realPos++] = s[i];
                length++;
            }
        }
        if(length){
            reverse(s.begin()+startPos,s.begin()+startPos+length);
        }
        s.erase(realPos);
        s.erase(s.find_last_not_of(" ") + 1);
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
