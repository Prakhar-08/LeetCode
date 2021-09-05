// Leetcode - 78
// Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

class Solution {
public:
    vector<vector<int>> res;
        
    void solve(vector<int> nums, vector<int> output) {
        if(nums.size() == 0) {
            res.push_back(output);
            return;
        }
         
        vector<int> temp(output);
        
        temp.push_back(nums[0]);
        nums.erase(nums.begin());
        
        solve(nums, output);
        solve(nums, temp);
        
        return;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> output;
        solve(nums, output);
        
        return res;
    }
};