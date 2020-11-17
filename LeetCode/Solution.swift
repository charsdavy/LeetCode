//
//  Solution.swift
//  LeetCode
//
//  Created by dengwei on 2020/11/17.
//

import Foundation

class Solution: NSObject {
    /**
     * 1. Two Sum
       两数之和
     *
     * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
     * You may assume that each input would have exactly one solution, and you may not use the same element twice.
     * Example:
     *  Given nums = [2, 7, 11, 15], target = 9,
     *  Because nums[0] + nums[1] = 2 + 7 = 9,
     *  return [0, 1].
     *
     * Note: The returned array must be malloced, assume caller calls free().
     */
    public func twoSum(nums: NSArray, target: Int) -> NSArray {
        let dic: NSMutableDictionary = NSMutableDictionary()
        for i in 0 ..< nums.count {
            let value: Int = nums.object(at: i) as! Int
            let complement: Int = target - value
            
            if let index: NSNumber = dic.object(forKey: String.init(format: "%d", complement)) as? NSNumber {
                return [index, i]
            }
            dic.setValue(NSNumber.init(value: i), forKey: String.init(format: "%d", value))
        }
        return []
    }
}
