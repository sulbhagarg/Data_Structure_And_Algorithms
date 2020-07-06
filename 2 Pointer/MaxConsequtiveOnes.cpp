/* Given a binary array, find the maximum number of consecutive 1s in this array. */

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0,j=0;
        int n=nums.size();
        if(n<1)
            return 0;
        int ans=0;
        while(j<n){
            if(nums[j]==0){
                if(i!=-1)
                    ans=max(ans,j-i);
                i=-1;
            }
            else if(j>0 && nums[j-1]==0 && nums[j]==1)
                i=j;
            else if(nums[j]==1)
                ans=max(ans,j-i+1);
            j++;
        }
        if(i!=-1)
            ans=max(ans,j-i);
        return ans;
    }
};

// OPTIMISED
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_cnt = 0, cnt = 0;
        for (auto n : nums) {
            if (n == 1) max_cnt = max(++cnt, max_cnt);
            else cnt = 0;
        }
        return max_cnt;
    }
};
