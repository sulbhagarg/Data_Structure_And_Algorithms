//Given a collection of intervals, merge all overlapping intervals.

// It's my habit to define sortcol for sorting a 2D vector, you may skip that if dealing with 1st col.

class Solution {
public:
    static bool sortcol(const vector<int>& v1, const vector<int> &v2){
        return v1[0]<v2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), sortcol);
        vector<vector<int>> ans;
        if(intervals.size()>0)
            ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(ans[ans.size()-1][1]>=intervals[i][0]){
                ans[ans.size()-1][1] = max(intervals[i][1], ans[ans.size()-1][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
