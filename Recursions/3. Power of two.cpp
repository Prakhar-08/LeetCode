// Leetcode - 231
// Given an integer n, return true if it is a power of two. Otherwise, return false.
// An integer n is a power of two, if there exists an integer x such that n == 2x.


class Solution {
public:
    bool isPowerOfTwo(int n) {
    // Approach 1
        return (n > 0 and (n & (n-1)) == 0);
        

    //Approach 2
        if(n == 1)
            return true;
        
        if(n == 0)
            return false;
        
        return (n%2 == 0 and isPowerOfTwo(n/2));
    }
};