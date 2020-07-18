/* Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false */

class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26]={0};
        for(int i=0;i<s.length();i++)
            a[s[i]-'a']++;
        for(int i=0;i<t.length();i++)
            a[t[i]-'a']--;
        for(int i=0;i<26;i++)
            if(a[i]!=0)
                return false;
        return true;
    }
};
