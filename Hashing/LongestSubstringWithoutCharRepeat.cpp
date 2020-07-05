// Given a string, find the length of the longest substring without repeating characters.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int l=0;
        int len=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end() && mp[s[i]]>=l){
                len = max(len, i-l);
                l = mp[s[i]]+1;
            }
            mp[s[i]] = i;
        }
        len = max(len, n-l);
        return len;
    }
};
