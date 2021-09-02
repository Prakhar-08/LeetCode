// Leetcode - 344
// Write a function that reverses a string. The input string is given as an array of characters s.

class Solution {
public:
    void reverse(vector<char>& s, int start, int end) {
        if(start >= end)
            return;
        
        swap(s[start], s[end]);
        reverse(s, start+1, end-1);
    }
    
    void reverseString(vector<char>& s) {
        
        //Approach 1 (using Recursion)
        reverse(s, 0, s.size()-1);
        
        
        //Approach 2 (using STL)
        // reverse(s.begin(), s.end());    
        
        
        //Aproach 3 (using loop)
        // int st = 0, en = s.size()-1;
        // while(st <= en) {
        //     swap(s[st], s[en]);
        //     st++; en--;
        // }
    }
};