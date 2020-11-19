//
//  Solution.cpp
//  LeetCode-C++
//
//  Created by dengw on 2020/11/18.
//

#include <vector>

class Solution
{
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix);
};

using namespace std;


/**
 https://leetcode.com/problems/spiral-matrix/
 54. Spiral Matrix
 
 Given an m x n matrix, return all elements of the matrix in spiral order.
 
 Example 1:
 Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 Output: [1,2,3,6,9,8,7,4,5]
 
 Example 2:
 Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 Output: [1,2,3,4,8,12,11,10,9,5,6,7]
  
 Constraints:

 m == matrix.length
 n == matrix[i].length
 1 <= m, n <= 10
 -100 <= matrix[i][j] <= 100
 */
vector<int> Solution::spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return {};
    }
    int rows = (int)matrix.size(), columns = (int)matrix[0].size();
    vector<int> order;
    int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
    while (left <= right && top <= bottom) {
        for (int column = left; column <= right; column++) {
            order.push_back(matrix[top][column]);
        }
        for (int row = top + 1; row <= bottom; row++) {
            order.push_back(matrix[row][right]);
        }
        if (left < right && top < bottom) {
            for (int column = right - 1; column > left; column--) {
                order.push_back(matrix[bottom][column]);
            }
            for (int row = bottom; row > top; row--) {
                order.push_back(matrix[row][left]);
            }
        }
        left++;
        right--;
        top++;
        bottom--;
    }
    return order;
}
