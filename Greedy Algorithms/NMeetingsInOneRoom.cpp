/* There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is start time of meeting i and F[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room? */

bool sortcol(const vector<int> &v1, const vector<int> &v2){
    return v1[1]<v2[1];
}

vector<int> nMeetings(vector<vector<int>>& v, int n){
    sort(v.begin(), v.end(), sortcol);
    vector<int> ans;
    ans.push_back(v[0][2]);
    int maxTime=v[0][1];
    for(int i=1;i<n;i++){
        if(v[i][0]>=maxTime){
            ans.push_back(v[i][2]);
            maxTime = max(maxTime, v[i][1]);
        }
    }
    return ans;
}
