/* Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000. */

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<=1)
            return s;
        int start=0,len=1,n=s.length();
        string ans="";
        for(int i=0;i<n;i++){
            if(n-i<=len/2)
                break;
            int j=i,k=i;
            while(k<n-1 && s[k]==s[k+1])
                k++;
            while(k<n-1 && j>0 && s[k+1]==s[j-1]){
                k++;
                j--;
            }
            int newLen=k-j+1;
            if(newLen>len){
                len=newLen;
                start=j;
            }
        }
        ans = s.substr(start,len);
        return ans;
    }
};
