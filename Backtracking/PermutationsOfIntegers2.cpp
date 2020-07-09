/* Given a collection of numbers that might contain duplicates, return all possible unique permutations. */

class Solution {
public:
    bool isValid(vector<int>& temp, int num, map<int, int>& mp){
        for(int i=0;i<temp.size();i++){
            if(temp[i]==num && mp[num]==0)
                return false;
        }
        return true;
    }
    
    void permuteHelper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, int n, map<int, int>& mp){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if(isValid(temp, nums[i], mp)){
                temp.push_back(nums[i]);
                mp[nums[i]]--;
                permuteHelper(nums, ans, temp, n, mp);
                mp[nums[i]]++;
                temp.pop_back();
                while(i<n-1 && nums[i]==nums[i+1])
                    i++;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        map<int,int> mp;
        for(int i=0;i<n;i++)
            mp[nums[i]]++;
        permuteHelper(nums, ans, temp, n, mp);
        return ans;
    }
};
