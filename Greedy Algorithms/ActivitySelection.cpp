/* Given N activities with their start and finish times. 
Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
Note : The start time and end time of two activities may coincide. */

bool sortcol(const vector<int>& v1, const vector<int>& v2){
    return v1[1]<v2[1];
}

int activitySelection(vector<vector<int>>& A, int n){
    if(n<1)
        return 0;
    int count=1;
    sort(A.begin(),A.end(),sortcol);
    int maxTime = A[0][1];
    for(int i=1;i<n;i++){
        if(A[i][0]>=maxTime){
            count++;
            maxTime = A[i][1];
        }
    }
    return count;
}
