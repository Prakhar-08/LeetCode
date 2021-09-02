// Leetcode - 11
// Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.
// Notice that you may not slant the container.

class Solution {
public:
    
//Recursive Approach
    void solve(vector<int>& height, int s, int e, int& sum) {
        if(s >= e)
            return;
        
        sum = max(sum, min(height[s],height[e])*(e-s));
        
        if(height[s] <= height[e])
            solve(height, s+1, e, sum);
        else 
            solve(height, s, e-1, sum);
    }
    
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, sum = 0;
        
        solve(height, i, j, sum);
        return sum; 
    }
    
//Iterative Approach
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, sum = 0;
    
        while(i < j) {
            sum = max(sum, min(height[j],height[i])*(j-i));

            if(height[i] <= height[j])
                i++;
            else 
                j--;
        }
        
        return sum; 
    }
};