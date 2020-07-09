/* Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.
The same repeated number may be chosen from candidates unlimited number of times.
Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations. */

class Solution {
public:
    void combinationSumHelper(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& temp, int target, int sum, int idx){
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        if(sum>target)
            return;
        for(int i=idx;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            combinationSumHelper(candidates, ans, temp, target, sum+candidates[i], i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        combinationSumHelper(candidates, ans, temp, target, 0, 0);
        return ans;
    }
};
