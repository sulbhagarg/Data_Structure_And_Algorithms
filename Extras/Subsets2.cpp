/* Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets. */

class Solution {
public:
    int k;
    void subsetHelper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, int idx){
        if(temp.size()==k){
            ans.push_back(temp);
        }
        for(int i=idx;i<nums.size();i++){
            temp.push_back(nums[i]);
            subsetHelper(nums, ans, temp, i+1);
            temp.pop_back();
            while(i<nums.size()-1 && nums[i]==nums[i+1])
                i++;
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        for(k=0;k<nums.size()+1;k++)
            subsetHelper(nums, ans, temp, 0);   
        return ans;
    }
};
