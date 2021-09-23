class Solution {
public:
    vector<string> digs = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void solve(string digits, vector<string>& ans) {
        if(digits.size() == 0)
            return;
        
        int num = digits[0] - '0';
        solve(digits.substr(1), ans);
        
        int n = digs[num].size();
        
        if(ans.size() == 0) {
            for(int i=0; i<n; i++)
                ans.push_back(string(1, digs[num][i]));
        } 
        else {
            vector<string> temp;
            for(int i=0; i<ans.size(); i++) {
                for(int j=0; j<n; j++) {
                    temp.push_back(digs[num][j] + ans[i]);
                }
            }
            
            ans = temp;
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) {
            return {};
        }
        
        vector<string> ans;
        
        solve(digits, ans);
        return ans;
    }
};