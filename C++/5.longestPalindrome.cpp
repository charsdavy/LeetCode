//
//  Solution.cpp
//  LeetCode-C++
//
//  Created by dengw on 2020/11/18.
//

#include <string>

using namespace std;

class Solution
{
public:    
    std::pair<int, int> expandAroundCenter(const std::string& s, int left, int right);
    std::string longestPalindrome(std::string s);
};

/**
 5. Longest Palindromic Substring
 动态规划法
 
 Given a string s, return the longest palindromic substring in s.

 Example 1:

 Input: s = "babad"
 Output: "bab"
 Note: "aba" is also a valid answer.
 Example 2:

 Input: s = "cbbd"
 Output: "bb"
 Example 3:

 Input: s = "a"
 Output: "a"
 Example 4:

 Input: s = "ac"
 Output: "a"
  

 Constraints:

 1 <= s.length <= 1000
 s consist of only digits and English letters (lower-case and/or upper-case),
 */
string Solution::longestPalindrome(string s)
{
    int count = (int)s.size();
    vector<vector<int> > dp(count, vector<int>(count));
    string ans;
    for (int m = 0; m < count; ++m) {
        for (int i = 0; i + m < count; ++i) {
            int j = i + m;
            if (m == 0) {
                dp[i][j] = 1;
            } else if (m == 1) {
                dp[i][j] = (s[i] == s[j]);
            } else {
                dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
            }
            
            if (dp[i][j] && m + 1 > ans.size()) {
                ans = s.substr(i, m + 1);
            }
        }
    }
    return ans;
}

/**
 5. Longest Palindromic Substring
 中心扩散法
 
 Given a string s, return the longest palindromic substring in s.

 Example 1:

 Input: s = "babad"
 Output: "bab"
 Note: "aba" is also a valid answer.
 Example 2:

 Input: s = "cbbd"
 Output: "bb"
 Example 3:

 Input: s = "a"
 Output: "a"
 Example 4:

 Input: s = "ac"
 Output: "a"
  

 Constraints:

 1 <= s.length <= 1000
 s consist of only digits and English letters (lower-case and/or upper-case),
 */
pair<int, int> Solution::expandAroundCenter(const string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        --left;
        ++right;
    }
    return {left + 1, right - 1};
}

string Solution::longestPalindrome(string s)
{
    int start = 0, end = 0;
    for (int i = 0; i < s.size(); ++i) {
        auto [left1, right1] = expandAroundCenter(s, i, i);
        auto [left2, right2] = expandAroundCenter(s, i, i + 1);
        if (right1 - left1 > end - start) {
            start = left1;
            end = right1;
        }
        if (right2 - left2 > end - start) {
            start = left2;
            end = right2;
        }
    }
    return s.substr(start, end - start + 1);
}