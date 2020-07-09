/* Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
Each number in candidates may only be used once in the combination.
Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations. */

class Solution {
public:
    void combinationSum2Helper(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& temp, int sum, int idx){
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        if(sum>target){
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            combinationSum2Helper(candidates, target, ans, temp, sum+candidates[i], i+1);
            temp.pop_back();
            while(i<candidates.size()-1 && candidates[i]==candidates[i+1])
                i++;
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        combinationSum2Helper(candidates, target, ans, temp, 0, 0);
        return ans;
    }
};
