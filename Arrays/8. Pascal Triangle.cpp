// Leetcode - 118 Pascal's Triangle
// Given an integer numRows, return the first numRows of Pascal's triangle.
// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> res(n);
        
        res[0] = {1};
        
        for(int i=1; i<n; i++)
        {
            int m = res[i-1].size()+1;
            vector<int> tmp(m);
            
            tmp[0] = 1;
            for(int j=1; j<m-1; j++) 
            {
                tmp[j] = res[i-1][j-1] + res[i-1][j];
            }
            tmp[m-1] = 1;
            
            res[i] = tmp;
        }
        
        return res;
    }
};