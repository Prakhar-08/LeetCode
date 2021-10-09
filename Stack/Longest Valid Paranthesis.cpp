// Leetcode - 32
//Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> res;
        res.push(-1);
        int ans=0;
        
        for(int i=0; i<s.size(); i++) {
            int t = res.top();
            
            if(t != -1 and s[i] == ')' and s[t] == '(') {
                res.pop();
                ans = max(ans, i-res.top());
            } else {
                res.push(i);
            }
        }
        
        return ans;
    }
};