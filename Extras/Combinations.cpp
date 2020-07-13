/* Given two integers n and k, return all possible combinations of k numbers out of 1 ... n. */

class Solution {
public:
    void combineHelper(int n, int k, vector<vector<int>>& ans, vector<int>& temp, int idx){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<=n;i++){
            temp.push_back(i);
            combineHelper(n,k,ans,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        combineHelper(n, k, ans, temp, 1);
        return ans;
    }
};
