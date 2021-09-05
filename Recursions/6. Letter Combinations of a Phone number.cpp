// Leetcode - 17
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


class Solution {
public:
    vector<string> vec = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void solve(string d, vector<string>& res) {
        if(d.size() == 0) {
            res[0] = "";
            return;
        }
        
        int num = d[0] - '0';
        solve(d.substr(1), res);
        
        int n = vec[num].size();
        int size = vec[num].size()*res.size();
        
        int k=0;
        vector<string> tmp(size);
        for(int i=0; i<res.size(); i++) {
            for(int j=0; j<n; j++) {
                tmp[k] = vec[num][j] + res[i];
                k++;
            }
        }
        
        for(int i=0; i<size; i++) {
            res[i] = tmp[i];
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        
        if(digits.size() == 0) {
            return {};
        }
        
        int n = 1;
        for(int i=0; i<digits.size(); i++) {
            int idx = digits[i] - '0';
            n = n*vec[idx].size();
        }
        
        vector<string> res(n);
        solve(digits, res);
        return res;
    }
};