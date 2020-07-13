/* Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1]. */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        vector<int> ans(2, -1);
        if(r<0)
            return ans;
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]<target){
                l=mid+1;
            } else {
                r=mid;
            }
        }
        if(nums[l]!=target)
            return ans;
        ans[0]=l;
        r=nums.size()-1;
        while(l<r){
            int mid=(l+r+1)/2;
            if(nums[mid]>target){
                r=mid-1;
            } else {
                l=mid;
            }
        }
        ans[1]=r;
        return ans;
    }
};
