// Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

// O(nlogn) approach would be to do sort at first, and then perform binary search, or linear search.
// Optimised one would be to use XOR or sum approach.

// Sum - Approach
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0,temp=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            temp+=nums[i];
            sum+=(i+1);
        }
        return sum-temp;
    }
};

// XOR - Approach
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        for(int i=1;i<=n;i++){
            res^=i;
            res^=nums[i-1];
        }
        return res;
    }
};
