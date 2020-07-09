/* Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.
Input:
The first line contains an integer 'T' denoting the total number of test cases. Each test case constitutes of two lines. First line contains 'N', representing the number of elements in the set and the second line contains the elements of the set.
Output:
Print YES if the given set can be partioned into two subsets such that the sum of elements in both subsets is equal, else print NO. */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool canPartitionHelper(vector<int>& nums, int target, int idx){
    if(target<=0)
        return target==0;
    for(int i=idx;i<nums.size();i++){
        if(canPartitionHelper(nums,target-nums[i],i+1))
            return true;
    }
    return false;
}
bool canPartition(vector<int>& nums) {
    int sum=0;
    for(int i=0;i<nums.size();i++)
        sum+=nums[i];
    if(sum%2)
        return false;
    return canPartitionHelper(nums, sum/2, 0);
}

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int> v(n);
	    for(int i=0;i<n;i++)
	        cin >> v[i];
	    if(canPartition(v))
	        cout << "YES" << endl;
	    else
	        cout << "NO" << endl;
	}
	return 0;
}
