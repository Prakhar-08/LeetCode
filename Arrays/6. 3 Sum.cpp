// Leetcode - 15 3 Sum (*Important)
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        
        if(nums.size() < 3)
            return res;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size()-2; i++) {
            if(i == 0 || (i > 0 and nums[i] != nums[i-1])) {

                int start = i+1, end = nums.size()-1;
                while(start < end) {
                    if(nums[i] + nums[start] + nums[end] < 0)
                        start++;
                    
                    else if(nums[i] + nums[start] + nums[end] > 0)
                        end--;
                    
                    else {
                        res.push_back({nums[i], nums[start], nums[end]});
                        
                        while(start < end and nums[start] == nums[start+1])
                            start++;
                        while(start < end and nums[end] == nums[end-1])
                            end--;
                        
                        start++; end--;
                    }   
                }
            }
        }
        
        return res;
    }
};