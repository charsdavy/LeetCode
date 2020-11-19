//
//  LRUCache.cpp
//  LeetCode-C++
//
//  Created by dengwei on 2020/11/19.
//

#include <unordered_set>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s);
};

/**
 https://leetcode.com/problems/longest-substring-without-repeating-characters/
 
 3. Longest Substring Without Repeating Characters
 
 Given a string s, find the length of the longest substring without repeating characters.

  

 Example 1:

 Input: s = "abcabcbb"
 Output: 3
 Explanation: The answer is "abc", with the length of 3.
 Example 2:

 Input: s = "bbbbb"
 Output: 1
 Explanation: The answer is "b", with the length of 1.
 Example 3:

 Input: s = "pwwkew"
 Output: 3
 Explanation: The answer is "wke", with the length of 3.
 Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 Example 4:

 Input: s = ""
 Output: 0
  

 Constraints:

 0 <= s.length <= 5 * 104
 s consists of English letters, digits, symbols and spaces.
 */
int Solution::lengthOfLongestSubstring(string s)
{
    // 哈希集合，记录每个字符是否出现过
    unordered_set<char> occ;
    int n = (int)s.size();
    // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
    int rk = -1, ans = 0;
    // 枚举左指针的位置，初始值隐性地表示为 -1
    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            // 左指针向右移动一格，移除一个字符
            occ.erase(s[i - 1]);
        }
        while (rk + 1 < n && !occ.count(s[rk + 1])) {
            // 不断地移动右指针
            occ.insert(s[rk + 1]);
            ++rk;
        }
        // 第 i 到 rk 个字符是一个极长的无重复字符子串
        ans = max(ans, rk - i + 1);
    }
    return ans;
}