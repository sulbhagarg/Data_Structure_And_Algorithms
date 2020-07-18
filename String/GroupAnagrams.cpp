/* Given an array of strings, group anagrams together.
Example:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
] */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<string> temp;
        int n=strs.size();
        int dp[n][26];
        for(int i=0;i<n;i++)
            for(int j=0;j<26;j++)
                dp[i][j]=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<strs[i].length();j++)
                dp[i][strs[i][j]-'a']++;
        bool visited[n];
        for(int i=0;i<n;i++)
            visited[i]=false;
        for(int i=0;i<n;i++){
            if(visited[i])
                continue;
            temp.clear();
            temp.push_back(strs[i]);
            for(int j=i+1;j<n;j++){
                if(visited[j])
                    continue;
                int flag=0;
                for(int k=0;k<26;k++){
                    if(dp[i][k]!=dp[j][k]){
                        flag=1;
                        break;
                    }
                }
                if(!flag){
                    visited[j]=true;
                    temp.push_back(strs[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
