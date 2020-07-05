// Given an integer n, return the number of trailing zeroes in n!.

class Solution {
public:
    int trailingZeroes(int n) {
        long long int x=5;
        long long int ans=0;
        while(x<=n){
            ans+=n/x;
            x*=5;
        }
        return ans;
    }
};
