/* Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero. */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int n=nums.size();
        int target=0;
        map<int, int> mp;
        if(n<3)
            return ans;
        for(int i=0;i<n-2;i++){
            if(mp.find(nums[i])!=mp.end())
                continue;
            int temp1 = target-nums[i];
            mp[nums[i]]=1;
            temp.push_back(nums[i]);
            int l=i+1;
            int r=n-1;
            while(l<r){
                if(nums[l]+nums[r]>temp1)
                    r--;
                else if(nums[l]+nums[r]<temp1)
                    l++;
                else{
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    ans.push_back(temp);
                    temp.pop_back();
                    temp.pop_back();
                    l++;
                    r--;
                }
            }
            temp.pop_back();
        }
        if(ans.size()==0)
            return ans;
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]==ans[i+1]){
                ans.erase(ans.begin()+i);
                i--;
            }
        }
        return ans;
    }
};
