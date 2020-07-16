/* Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "". */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        string ans="";
        int minLen=INT_MAX;
        for(auto str: strs)
            if(str.length()<minLen)
                minLen=str.length();
        for(int i=0;i<minLen;i++){
            char ch=strs[0][i];
            int flag=0;
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]!=ch){
                    flag=1;
                    break;
                }
            }
            if(flag)
                break;
            ans+=ch;
        }
        return ans;
    }
};
