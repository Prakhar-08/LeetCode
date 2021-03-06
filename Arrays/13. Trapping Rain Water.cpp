// Leetcode - 42
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.


// Approach 1 - TC: O(n) SC: O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<=2)
            return 0;
        
        vector<int> left(n), right(n);
        
        left[0] = height[0];
        for(int i=1; i<n; i++) {
            left[i] = max(height[i], left[i-1]);
        }
        
        right[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--) {
            right[i] = max(height[i], right[i+1]);
        }
        
        int sum=0;
        for(int i=1; i<n-1; i++) {
            if(height[i] < left[i] and height[i] < right[i])
                sum += min(left[i],right[i]) - height[i];
        }
        return sum;
    }
};

//Approach2 Optimal solution
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<=2)
            return 0;
        
        int l = 0, r = n-1, leftmax = 0, rightmax=0, sum=0;
        
        while(l < r) {
            if(height[l] <= height[r]) {
                if(height[l] >= leftmax)
                    leftmax = height[l];
                else
                    sum += leftmax - height[l];
                
                l++;
            }
            else {
                if(height[r] >= rightmax)
                    rightmax = height[r];
                else 
                    sum += rightmax - height[r];
                
                r--;
            }
        }
        return sum;
    }
};