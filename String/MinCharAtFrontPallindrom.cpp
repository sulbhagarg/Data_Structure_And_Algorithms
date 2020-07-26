/* Given a string s, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation. */

/* HARD */

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        string temp = s+"#"+rev;
        int n=temp.length();
        vector<int> lps(n);
        lps[0]=0;
        int i=1,len=0;
        while(i<n){
            if(temp[i]==temp[len]){
                len++;
                lps[i]=len;
                i++;
            } else {
                if(len!=0){
                    len=lps[len-1];
                } else {
                    lps[i]=0;
                    i++;
                }
            }
        }
        len = s.length() - lps.back();
        temp.clear();
        for(int i=1;i<=len;i++){
            temp+=s[s.length()-i];
        }
        return temp+s;
    }
};
