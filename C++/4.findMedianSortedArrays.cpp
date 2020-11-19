//
//  Solution.cpp
//  LeetCode-C++
//
//  Created by dengw on 2020/11/18.
//

class Solution
{
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2);
};

/**
 https://leetcode.com/problems/median-of-two-sorted-arrays/
 
 4. Median of Two Sorted Arrays
 划分数组
 
 Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

 Follow up: The overall run time complexity should be O(log (m+n)).


 Example 1:

 Input: nums1 = [1,3], nums2 = [2]
 Output: 2.00000
 Explanation: merged array = [1,2,3] and median is 2.
 Example 2:

 Input: nums1 = [1,2], nums2 = [3,4]
 Output: 2.50000
 Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 Example 3:

 Input: nums1 = [0,0], nums2 = [0,0]
 Output: 0.00000
 Example 4:

 Input: nums1 = [], nums2 = [1]
 Output: 1.00000
 Example 5:

 Input: nums1 = [2], nums2 = []
 Output: 2.00000
  

 Constraints:

 nums1.length == m
 nums2.length == n
 0 <= m <= 1000
 0 <= n <= 1000
 1 <= m + n <= 2000
 -106 <= nums1[i], nums2[i] <= 106
 */
double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }
    int m = (int)nums1.size();
    int n = (int)nums2.size();
    int left = 0, right = m, ansi = -1;
    // median1：前一部分的最大值
    // median2：后一部分的最小值
    int median1 = 0, median2 = 0;
    while (left <= right) {
        // 前一部分包含 nums1[0 .. i - 1] 和 nums2[0 .. j - 1]
        // 后一部分包含 nums1[i .. m - 1] 和 nums2[j .. n - 1]
        int i = (left + right) / 2;
        int j = (m + n + 1) / 2 - i;
        // nums_im1, nums_i, nums_jm1, nums_j 分别表示 nums1[i - 1], nums1[i], nums2[j - 1], nums2[j]
        int nums_im1 = (i == 0 ? INT_MIN : nums1[i - 1]);
        int nums_i = (i == m ? INT_MAX : nums1[i]);
        int nums_jm1 = (j == 0 ? INT_MIN : nums2[j - 1]);
        int nums_j = (j == n ? INT_MAX : nums2[j]);

        if (nums_im1 <= nums_j) {
            ansi = i;
            median1 = max(nums_im1, nums_jm1);
            median2 = min(nums_i, nums_j);
            left = i + 1;
        } else {
            right = i - 1;
        }
    }
    return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
}
