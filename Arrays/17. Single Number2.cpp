// Leetcode - 137
// Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
// You must implement a solution with a linear runtime complexity and use only constant extra space.


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++) {
            m[nums[i]]++;
        }
        
        int ans=0;
        for(auto i: m) {
            if(i.second == 1) {
                ans = i.first;
            }
        }
        
        return ans;
    }
};