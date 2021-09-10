// Leetcode - 119 Pascal's Triangle 2
// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

//Approach 1
class Solution {
public:
    vector<int> getRow(int r) {
        vector<int> vec(r+1, 0);
        
        vec[0] = 1;
        
        for(int i=0; i<r+1; i++) {
            for(int j=i; j>0; j--) {
                vec[j] = vec[j] + vec[j-1];
            }
        }
        
        return vec;
    }
};

// Approach 2
class Solution {
public:
    vector<int> getRow(int r) {
        vector<vector<int>> res(r+1);
        
        res[0] = {1};
        
        for(int i=1; i<r+1; i++)
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
        
        return res[r];
    }
};