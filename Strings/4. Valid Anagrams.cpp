// Leetcode - 242 Valid Anagram
//Given two strings s and t, return true if t is an anagram of s, and false otherwise.

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        if(s == t)
            return true;
        else return false;
    }
};