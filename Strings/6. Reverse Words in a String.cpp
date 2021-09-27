// Leetcode -159

// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

class Solution {
public:
    string reverseWords(string s) {
        stack<string> res;
        string ans;
        
        for(int i=0; i<s.size(); i++) {
            if(s[i] == ' ')
                continue;
            
            string word;
            while(i < s.size() and s[i] != ' ') {
                word += s[i];
                i++;
            }
            
            res.push(word);
        }
        
        while(!res.empty()) {
            ans += res.top();
            res.pop();
            
            if(!res.empty())
                ans += " ";
        }
        
        return ans;
    }
};