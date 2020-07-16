/* Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack. */

class Solution {
public:
    int strStr(string haystack, string needle) {
        int d=256;
        int q=101;
        int n=haystack.length();
        int m=needle.length();
        if(m>n)
            return -1;
        if(m==0)
            return 0;
        int h=1,p=0,t=0;
        for(int i=0;i<m-1;i++)
            h=(h*d)%q;
        for(int i=0;i<m;i++){
            p=(d*p+haystack[i])%q;
            t=(d*t+needle[i])%q;
        }
        for(int i=0;i<=n-m;i++){
            if(p==t){
                int flag=0;
                for(int j=0;j<m;j++){
                    if(haystack[i+j]!=needle[j]){
                        flag=1;
                        break;
                    }
                }
                if(!flag)
                    return i;
            }
            if(i<n-m){
                p=(d*(p-haystack[i]*h)+haystack[i+m])%q;
                if(p<0)
                    p=p+q;
            }
        }
        return -1;
    }
};
