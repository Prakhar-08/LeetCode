// Leetcode - 1
//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//You can return the answer in any order.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2);
        unordered_map<int, int> mp;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(mp.find(target - nums[i]) == mp.end()) 
            {
                mp[nums[i]] = i;
            } 
            else
            {
                res[0] = i;
                res[1] = mp[target - nums[i]];
                break;
            }
        }
        
        return res;
    }
};