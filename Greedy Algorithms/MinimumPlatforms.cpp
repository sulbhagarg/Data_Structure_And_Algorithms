/* Given arrival and departure times of all trains that reach a railway station. Your task is to find the minimum number of platforms required for the railway station so that no train waits.

Note: Consider that all the trains arrive on the same day and leave on the same day. Also, arrival and departure times will not be same for a train, but we can have arrival time of one train equal to departure of the other. In such cases, we need different platforms, i.e at any given instance of time, same platform can not be used for both departure of a train and arrival of another. */

bool sortcol(const vector<int>& v1, const vector<int>& v2){
    return v1[0]<v2[0];
}

int minPlatform(vector<vector<int>>& interval, int n){
    if(n<1)
        return 0;
    sort(interval.begin(), interval.end(), sortcol);
    int ans=0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<n;i++){
        if(pq.size() && pq.top()<interval[i][0])
            pq.pop();
        pq.push(interval[i][1]);
        ans = max(ans, (int)pq.size());
    }
    return ans;
}
