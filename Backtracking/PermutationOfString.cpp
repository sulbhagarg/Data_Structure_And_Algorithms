/* Given a string S. The task is to print all permutations of a given string.
Input:
The first line of input contains an integer T, denoting the number of test cases. Each test case contains a single string S in capital letter.
Output:
For each test case, print all permutations of a given string S with single space and all permutations should be in lexicographically increasing order. */

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool isValid(string t, char s){
    for(int i=0;i<t.length();i++)
        if(t[i]==s)
            return false;
    return true;
}

void printPermutations(string s, int n, vector<string>& ans, string t){
    if(t.length()==n){
        ans.push_back(t);
        return;
    }
    for(int i=0;i<n;i++){
        if(isValid(t,s[i]))
            printPermutations(s,n,ans,t+s[i],i+1);
    }
}

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    string s;
	    cin >> s;
	    sort(s.begin(),s.end());
	    vector<string> ans;
	    string temp;
	    int n=s.length();
	    printPermutations(s,n,ans,temp);
	    for(int i=0;i<ans.size();i++){
	        cout << ans[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}
