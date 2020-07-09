/* Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s. */

class Solution {
public:
    bool isValid(string s){
        string temp=s;
        reverse(s.begin(),s.end());
        return temp==s;
    }
    
    void partitionHelper(string s, vector<vector<string>>& ans, vector<string> temp, int n, int idx){
        if(idx==n){
            ans.push_back(temp);
            return;
        }
        string t="";
        for(int i=idx;i<n;i++){
            t+=s[i];
            if(isValid(t)){
                temp.push_back(t);
                partitionHelper(s, ans, temp, n, i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        int n=s.length();
        partitionHelper(s, ans, temp, n, 0);
        return ans;
    }
};
