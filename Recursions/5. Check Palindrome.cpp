// Leetcode - 9
// Given an integer x, return true if x is palindrome integer.
// An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.

class Solution {
public:
    bool check(string s, int start, int end) {
        if(start >= end)
            return true;
        
        if(s[start] != s[end])
            return false;
        
        return check(s, start+1, end-1);
    }
    
    bool isPalindrome(int x) {
        string s = to_string(x);
        
        return check(s, 0, s.size()-1);
    }
};