/* Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.
Where:
A[i][0] = start time of the ith meeting.
A[i][1] = end time of the ith meeting.
Find the minimum number of conference rooms required so that all meetings can be done. */

bool sortcol( const vector<int>& v1, 
               const vector<int>& v2 ) { 
 return v1[0] < v2[0]; 
} 

int Solution::solve(vector<vector<int> > &A) {
    sort(A.begin(),A.end(),sortcol);
    int ans=0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<A.size();i++){
        while(!pq.empty() && pq.top()<=A[i][0]){
            pq.pop();
        }
        pq.push(A[i][1]);
        ans = max(ans, (int)pq.size());
    }
    return ans;
}
