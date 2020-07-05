// Given a column title as appear in an Excel sheet, return its corresponding column number.

class Solution {
public:
    int titleToNumber(string s) {
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            ans = ans*26 + (s[i]-'A' + 1);
        }
        return ans;
    }
};
