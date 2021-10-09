// 80. Remove Duplicates from Sorted Array II

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> mp;
        
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }
        
        int k=0;
        for(auto i: mp) {
            if(i.second > 1) {
                nums[k++] = i.first;
                nums[k++] = i.first;
            } else {
                nums[k++] = i.first;
            }
        }
        
        return k;
    }
};