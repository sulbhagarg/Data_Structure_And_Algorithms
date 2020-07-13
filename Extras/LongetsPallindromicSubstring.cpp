/* Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000. */

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<=1)
            return s;
        int start=0;
        int len=1;
        string ans="";
        for(int i=0;i<s.length();){
            if(s.size()-1<=len/2)
                break;
            int j=i,k=i;
            while(k<s.length()-1 && s[k]==s[k+1])
                k++;
            i=k+1;
            while(j>0 && k<s.length()-1 && s[k+1]==s[j-1]){
                k++;
                j--;
            }
            int temp=k-j+1;
            if(temp>len){
                len=temp;
                start=j;
            }
        }
        ans=s.substr(start,len);
        return ans;
    }
};
