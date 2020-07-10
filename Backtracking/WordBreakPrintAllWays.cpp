/* Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "snakesandladder",
dict = ["snake", "snakes", "and", "sand", "ladder"].

A solution is ["snakes and ladder",
           "snake sand ladder"].

Input:
The first line contains an integer T, denoting the number of test cases.
Every test case has 3 lines.
The first line contains an integer N, number of words in the dictionary.
The second line contains N strings denoting the words of the dictionary.
The third line contains a string s.

Output:
For each test case, print all possible strings in one line. Each string is enclosed in (). See Example.
If no string possible print "Empty" (without quotes). */

#include<bits/stdc++.h>
using namespace std;

void wordBreakHelper(string s, vector<string>& wordDict, string temp, 
                                    vector<vector<string>>& ans, vector<string>& t){
    if(s==temp){
        ans.push_back(t);
        return;
    }
    if(temp.length()>s.length())
        return;
    for(int i=0;i<temp.length();i++)
        if(temp[i]>s[i] || temp[i]!=s[i])
            return;
    for(int i=0;i<wordDict.size();i++){
        t.push_back(wordDict[i]);
        wordBreakHelper(s, wordDict, temp+wordDict[i], ans, t);
        t.pop_back();
    }
}
vector<vector<string>> wordBreak(string s, vector<string>& wordDict) {
    vector<vector<string>> ans;
    vector<string> t;
    wordBreakHelper(s, wordDict, "", ans, t);
    return ans;
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
	    vector<vector<string>> ans = wordBreak(s, wordDict);
	    for(int i=0;i<ans.size();i++){
	        cout << "(";
	        for(int j=0;j<ans[i].size();j++){
	            if(j!=ans[i].size()-1)
	                cout << ans[i][j] << " ";
	            else
	                cout << ans[i][j];
	        }
	        cout << ")";
	    }
	    cout <<  endl;
	}
	return 0;
}
