// Leetcode - 53
// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
//A subarray is a contiguous part of an array.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int res = nums[0];
        
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            
            if(sum > res)
                res = sum;
            if(sum < 0)
                sum = 0;
        }
        
        return res;
    }
};