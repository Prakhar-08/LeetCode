//Leetcode - 50
//Implement pow(x, n), which calculates x raised to the power n (i.e., xn). 

class Solution {
public:
    double getPow(double x, int n) {
        if(n==0)
            return 1.0;
        
        double val = getPow(x, n/2);
        
        if(n%2 == 0)
            return val*val;
        
        return x*val*val;
    }
    
    double myPow(double x, int n) {
        double res = getPow(x, abs(n));
        
        if(n < 0)
            return 1/res;
        
        return res;
    }
};