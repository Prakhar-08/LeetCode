//Leetcode - 50
//Implement pow(x, n), which calculates x raised to the power n (i.e., xn). 

class Solution {
public:
    double helper(double x , long n){
        if(n==0)
            return 1.0;
        if(n%2==0)
            return helper(x*x,n/2);
        else 
            return x*helper(x,n-1);
    }
    double myPow(double x, int n) {
        if(x==0)
            return 0;
        long nn=n;
        if(nn<0)
            return (double)1.0/helper(x,abs(nn));
        return helper(x,nn);
    }
};