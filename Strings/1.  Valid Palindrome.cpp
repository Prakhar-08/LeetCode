// Leetcode - 125
Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        while(i < j) {
            while(!isalnum(s[i]) and i<j)
                i++;
            
            while(!isalnum(s[j]) and i<j)
                j--;

            if(s[i] != s[j])
                return false;

            i++; j--;
        }
        
        return true;
    }
};