/* Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target. */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<vector<int>> v;
        if(n<4)
            return v;
        for(int i=0;i<n-3;i++){
            int temp = target-nums[i];
            for(int j=i+1;j<n-2;j++){
                int temp1 = temp-nums[j];
                int l=j+1;
                int r=n-1;
                while(l<r){
                    if(nums[l]+nums[r]>temp1)
                        r--;
                    else if(nums[l]+nums[r]<temp1)
                        l++;
                    else{
                        vector<int> t;
                        t.push_back(nums[i]);
                        t.push_back(nums[j]);
                        t.push_back(nums[l]);
                        t.push_back(nums[r]);
                        v.push_back(t);
                        l++;
                        r--;
                        while(l<n && nums[l]==nums[l-1])
                            l++;
                        while(r>j && nums[r]==nums[r+1])
                            r--;
                    }
                }
                while(j<n-3 && nums[j]==nums[j+1])
                    j++;
            }
            while(i<n-4 && nums[i]==nums[i+1])
                i++;
        }
        return v;
    }
};
