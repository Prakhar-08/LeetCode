// Leetcode - 20
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.

class Solution {
public:
    bool isValid(string s) {
        stack<char> res;
        
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                res.push(s[i]); 
                continue;
            }
            
            if(res.empty())
                return false;
            
            char t;
            switch(s[i]) {
                case ')':
                    t = res.top();
                    res.pop();
                    if(t == '[' || t == '{')
                        return false;
                    break;
                case ']':
                    t = res.top();
                    res.pop();
                    if(t == '(' || t == '{')
                        return false;
                    break;
                case '}':
                    t = res.top();
                    res.pop();
                    if(t == '[' || t == '(')
                        return false;
                    break;
            }
        }
        
        return res.empty();
    }
};