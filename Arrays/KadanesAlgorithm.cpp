// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_ending_here=0, max_so_far=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            max_ending_here+=nums[i];
            if(max_so_far<max_ending_here)
                max_so_far=max_ending_here;
            if(max_ending_here<0)
                max_ending_here=0;
        }
        return max_so_far;
    }
};
