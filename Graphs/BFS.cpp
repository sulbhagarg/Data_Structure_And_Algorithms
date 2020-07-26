/* Given a directed graph. The task is to do Breadth First Search of this graph. */

vector <int> bfs(vector<int> g[], int N) {
    vector<int> ans;
    queue<int> q;
    q.push(0);
    vector<bool> visited(N);
    for(int i=0;i<N;i++)
        visited[i]=false;
    while(!q.empty()){
        int idx=q.front();
        ans.push_back(idx);
        q.pop();
        for(int i=0;i<g[idx].size();i++){
            if(!visited[g[idx][i]]){
                visited[g[idx][i]]=true;
                q.push(g[idx][i]);
            }
        }
    }
    return ans;
}
