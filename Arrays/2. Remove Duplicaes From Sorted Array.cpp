// Letcode - 26. Remove Duplicates from Sorted Array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};