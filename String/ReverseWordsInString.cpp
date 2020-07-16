/* Given an input string, reverse the string word by word.
Example 1:
Input: "the sky is blue"
Output: "blue is sky the" */

class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        string ans="";
        string temp="";
        int flag=0;
        for(int i=0;i<n;i++){
            if(s[i]==' ' && flag){
                ans = ' ' + temp + ans;
                temp.clear();
                flag=0;
            } else if(s[i]!=' ') {
                temp+=s[i];
                flag=1;
            }
        }
        if(flag)
            ans = temp + ans;
        for(int i=0;i<ans.length();i++){
            if(ans[i]==' '){
                ans = ans.substr(1);
                i--;
            } else {
                break;
            }
        }
        return ans;
    }
};
