// Leetcode - 784 Letter Case Permutation
// Given a string s, we can transform every letter individually to be lowercase or uppercase to create another string.
// Return a list of all possible strings we could create. You can return the output in any order.

class Solution {
public:
    vector<string> res;
    
    void solve(string s, string output) {
        if(s.size() == 0) {
            res.push_back(output);
            return;
        }
        
        if(s[0] >= 97 and s[0] <= 122) { 
            char t = toupper(s[0]); 
            solve(s.substr(1), output + t);
        } 
        
        else if(s[0] >= 65 and s[0] <= 95) {
            char t = tolower(s[0]);
            solve(s.substr(1), output + t);
        }
        
        solve(s.substr(1), output + s[0]);
         
    }
    
    vector<string> letterCasePermutation(string s) {
        solve(s, "");
        
        return res;
    }
};