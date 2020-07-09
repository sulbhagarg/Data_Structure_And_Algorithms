/* Given a collection of distinct integers, return all possible permutations. */

class Solution {
public:
    bool isValid(vector<int>& temp, int num){
        for(int i=0;i<temp.size();i++){
            if(temp[i]==num)
                return false;
        }
        return true;
    }
    
    void permuteHelper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, int n){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if(isValid(temp, nums[i])){
                temp.push_back(nums[i]);
                permuteHelper(nums, ans, temp, n);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        int n=nums.size();
        permuteHelper(nums, ans, temp, n);
        return ans;
    }
};
