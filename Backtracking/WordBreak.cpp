/* Given an input string and a dictionary of words, find out if the input string can be segmented into a space-separated sequence of dictionary words. See following examples for more details.

Consider the following dictionary
{ i, like, sam, sung, samsung, mobile, ice,
  cream, icecream, man, go, mango}

Input:  ilike
Output: Yes
The string can be segmented as "i like".

Input:  ilikesamsung
Output: Yes
The string can be segmented as "i like samsung" or "i like sam sung". */

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool wordBreakHelper(string s, vector<string>& wordDict, string temp){
        if(s==temp)
            return true;
        if(temp.length()>s.length())
            return false;
        for(int i=0;i<temp.length();i++)
            if(temp[i]>s[i] || temp[i]!=s[i])
                return false;
        for(int i=0;i<wordDict.size();i++){
            if(wordBreakHelper(s, wordDict, temp+wordDict[i]))
               return true;
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        return wordBreakHelper(s, wordDict, "");
    }

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<string> wordDict(n);
	    for(int i=0;i<n;i++)
	        cin >> wordDict[i];
	    string s;
	    cin >> s;
	    if(wordBreak(s, wordDict))
	        cout << 1 << endl;
	    else
	        cout << 0 << endl;
	}
	return 0;
}
