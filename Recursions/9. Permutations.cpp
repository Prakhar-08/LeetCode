// Leetcode - 46 Permutations
// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

class Solution {
public:
    vector<vector<int>> res;
    void generate(vector<int> nums, int begin) {
        
        if(begin == nums.size()-1) {
            res.push_back(nums);
            return;
        }
        
        for(int i = begin; i<nums.size(); i++) {
            swap(nums[i], nums[begin]);
            generate(nums, begin+1);
            // swap(nums[i], nums[begin]);             // Bactrack Part
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        generate(nums, 0);
        return res;
    }
};

