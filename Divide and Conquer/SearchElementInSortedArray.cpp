/* You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

Follow up: Your solution should run in O(log n) time and O(1) space. */

// Efficient Approach
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0, r=nums.size()-1, mid;
        while(l<r){
            mid=l+(r-l)/2;
            if(nums[mid]==nums[mid^1])
                l=mid+1;
            else
                r=mid;
        }
        return nums[l];
    }
};

// Just thought Of a recursive approach to (But not an efficient one)
class Solution {
public:
    bool singleNonDuplicateHelper(vector<int>& nums, vector<int>& ans, int l, int r){
        if(l>r)
            return false;
        int mid=(l+r)/2;
        if((mid>0 && nums[mid-1]==nums[mid]) || (mid<nums.size()-1 && nums[mid]==nums[mid+1])){
            if(singleNonDuplicateHelper(nums, ans, l, mid-1) || singleNonDuplicateHelper(nums, ans, mid+1, r))
                return true;
        } else {
            ans.push_back(nums[mid]);
            return true;
        }
        return false;
    }
    int singleNonDuplicate(vector<int>& nums) {
        vector<int> ans;
        singleNonDuplicateHelper(nums, ans, 0, nums.size()-1);
        return ans[0];
    }
};
