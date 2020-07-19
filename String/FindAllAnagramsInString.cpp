/* Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
The order of output does not matter.

Example 1:
Input:
s: "cbaebabacd" p: "abc"
Output:
[0, 6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc". */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<int> ans,a(26,0),b(26,0);
        if(n<m)
            return ans;
        for(int i=0;i<m;i++){
            a[p[i]-'a']++;
            b[s[i]-'a']++;
        }
        if(a==b)
            ans.push_back(0);
        for(int i=m;i<n;i++){
            b[s[i]-'a']++;
            b[s[i-m]-'a']--;
            if(a==b)
                ans.push_back(i-m+1);
        }
        return ans;
    }
};
