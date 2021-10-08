// Leetcode - 647
// Given a string s, return the number of palindromic substrings in it.
// A string is a palindrome when it reads the same backward as forward.
// A substring is a contiguous sequence of characters within the string.

class Solution {
public:
    int countSubstrings(string s) {
        if(s.size() == 1)
            return 1;
        
        int count = 0;
        
        //odd Length 
        for(int i=0; i<s.size(); i++) {
            int l = i, r = i;
            
            while(l >= 0 and r < s.size() and s[l] == s[r]) {
                //cout << s.substr(l, r-l+1) << endl;
                count++;
                l--;
                r++;
            }
        }
        
        //even length
        for(int i=0; i<s.size(); i++) {
            int l = i, r = i+1;
            
            while(l >= 0 and r < s.size() and s[l] == s[r]) {
                //cout << s.substr(l, r-l+1) << endl;
                count++;
                l--;
                r++;
            }
        }
        
        return count;
    }
};