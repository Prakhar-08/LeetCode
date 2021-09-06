// Leetcode - 69 Sqrt(x)
// Given a non-negative integer x, compute and return the square root of x.
// Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.
// Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.

class Solution {
public:
    int mySqrt(int x) {
        long long int start = 0, end = x, ans = 0, mid;
        
        while(start <= end) {
            mid = (start + end)/2;
            
            if(mid*mid == x)
                return mid;
            
            else if(mid*mid < x) {
                ans = mid;
                start = mid+1;   
            }
            
            else 
                end = mid-1;
        }
        
        return ans;
    }
};