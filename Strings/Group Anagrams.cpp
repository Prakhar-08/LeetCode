// Leetcode - 49 Group Anagrams 
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        
        for(int i=0; i<s.size(); i++) {
            string temp = s[i];
            sort(temp.begin(), temp.end());
            
            m[temp].push_back(s[i]);
        }
        
        for(auto i: m) 
            res.push_back(i.second);
    
        return res;
    }
};