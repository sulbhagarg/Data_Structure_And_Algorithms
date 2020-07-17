/* Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000. */

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        vector<string> v;
        string temp="";
        int n=s.length();
        for(int i=0;i<n-1;i++){
            temp+=s[i];
            if(n%(i+1)==0)
                v.push_back(temp);
        }
        for(int i=0;i<v.size();i++){
            int flag=0;
            int t=v[i].length(),j=0;
            for(j=0;j<=n-t;j+=t){
                if(v[i]!=s.substr(j,t)){
                    flag=1;
                    break;
                }
            }
            if(j!=n)
                continue;
            if(!flag)
                return true;
        }
        return false;
    }
};
