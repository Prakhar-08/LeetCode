// Leetcode - 169
// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++) {
            m[nums[i]]++;
        }
        
        int ans=0, res=0;
        for(auto i: m) {
            if(ans < i.second) {
                ans = i.second;
                res = i.first;
            }
        }
        
        return res;
    }
};