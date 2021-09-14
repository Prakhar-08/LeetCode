// Leetcode - 90
// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

class Solution {
public:
    set<vector<int>> res;
    
    void solve(vector<int> nums, vector<int> output) {
        if(nums.size() == 0) {
            sort(output.begin(), output.end());
            res.insert(output);
            return;
        }
        
        vector<int> temp(output);
        
        temp.push_back(nums[0]);
        nums.erase(nums.begin());
        
        solve(nums, output);
        solve(nums, temp);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        vector<int> vec;
        solve(nums, vec);
        
        for(auto i : res) {
            ans.push_back(i);
        }
        
        return ans;
    }
};