class Solution {
public:

//Approach 1 using Set
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int i=0, j=0, res=0;
        
        while(i < s.size() && j < s.size()) {
            if(st.find(s[j]) == st.end()) {
                st.insert(s[j]);
                res = max(res, j-i+1);
                j++;
            }
            else {
                st.erase(s[i++]);
            }
        }
        
        return res;
    }

//Approach 2 Using map
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int i=0, j=0;
        unordered_map<char, int>m;
        
        while(j < s.size()) {
            m[s[j]]++;
            
            if(m.size() == j-i+1) {
                res = max(res, j-i+1);
                j++;
            }
            else if(m.size() < j-i+1) {
                while(m.size() < j-i+1) {
                    m[s[i]]--;
                    if(m[s[i]] == 0)
                        m.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return res;
    }
};