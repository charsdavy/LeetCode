//
//  Solution.cpp
//  LeetCode-C++
//
//  Created by dengw on 2020/11/18.
//

#include <stdio.h>
#include <vector>

class Solution
{
public:
    std::vector < std::vector < int >> threeSum(std::vector < int > &nums);
};

using namespace std;

/**
 https://leetcode.com/problems/3sum/
 
     15. 3Sum

     Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

     Notice that the solution set must not contain duplicate triplets.



     Example 1:

     Input: nums = [-1,0,1,2,-1,-4]
     Output: [[-1,-1,2],[-1,0,1]]
     Example 2:

     Input: nums = []
     Output: []
     Example 3:

     Input: nums = [0]
     Output: []


     Constraints:

     0 <= nums.length <= 3000
     -105 <= nums[i] <= 105
     */
vector<vector<int> > Solution::threeSum(vector<int>& nums)
{
    int count = (int)nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int> > ans;
    // 枚举 a
    for (int first = 0; first < count; ++first) {
        // 需要和上一次枚举的数不同
        if (first > 0 && nums[first] == nums[first - 1]) {
            continue;
        }
        // c 对应的指针初始指向数组的最右端
        int third = count - 1;
        int target = -nums[first];
        // 枚举 b
        for (int second = first + 1; second < count; ++second) {
            // 需要和上一次枚举的数不同
            if (second > first + 1 && nums[second] == nums[second - 1]) {
                continue;
            }
            // 需要保证 b 的指针在 c 的指针的左侧
            while (second < third && nums[second] + nums[third] > target) {
                --third;
            }
            // 如果指针重合，随着 b 后续的增加
            // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
            if (second == third) {
                break;
            }
            if (nums[second] + nums[third] == target) {
                ans.push_back({nums[first], nums[second], nums[third]});
            }
        }
    }
    return ans;
}
