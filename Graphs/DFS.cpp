/* Given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use recursive approach. */

void dfsHelper(vector<int> g[], vector<int>& ans, vector<bool>& visited, int idx, int N){
    for(int j=0;j<g[idx].size();j++){
        // cout << idx << " "; 
        if(g[idx][j]!=0 && !visited[g[idx][j]]){
            visited[g[idx][j]]=true;
            ans.push_back(g[idx][j]);
            dfsHelper(g,ans,visited,g[idx][j],N);
        }
    }
}

vector <int> dfs(vector<int> g[], int N)
{
    vector<int> ans;
    vector<bool> visited(N);
    for(int i=0;i<N;i++)
        visited[i]=false;
    ans.push_back(0);
    dfsHelper(g, ans, visited, 0, N);
    return ans;
}
