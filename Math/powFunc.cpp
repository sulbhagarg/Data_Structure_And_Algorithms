// Implement pow(x, n), which calculates x raised to the power n (x^n).
// O(logn) time complexity

// This solution comes handy always have this included in your template.

class Solution {
public:
    double sol(double x, int n){
        if(n==0)
            return 1;
        if(n%2)
            return x*sol(x*x, n/2);
        else
            return sol(x*x, n/2);
    }
    double myPow(double x, int n) {
        double ans = sol(x, n);
        if(n<0)
            ans=1/ans;
        return ans;
    }
};
