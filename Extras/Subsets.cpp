/* Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets. */

class Solution {
public:
    void subsetHelper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, int idx){
        if(idx>nums.size()-1){
            return;
        }
        for(int i=idx;i<nums.size();i++){
            temp.push_back(nums[i]);
            ans.push_back(temp);
            subsetHelper(nums, ans, temp, i+1);
            temp.pop_back();
            ans.push_back(temp);
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        subsetHelper(nums, ans, temp, 0);
        sort(ans.begin(), ans.end());
        for(int i=1;i<ans.size();i++){
            if(ans[i]==ans[i-1]){
                ans.erase(ans.begin()+i);
                i--;
            }
        }
        return ans;
    }
};
