/* Given a Directed Graph. Check whether it contains any cycle or not. */

bool dfs(vector<int> adj[], int idx, vector<bool>& visited, vector<bool>& recStack){
    visited[idx]=true;
    recStack[idx]=true;
    for(int i=0;i<adj[idx].size();i++){
        if(!visited[adj[idx][i]] && dfs(adj,adj[idx][i],visited,recStack))
            return true;
        if(recStack[adj[idx][i]])
            return true;
    }
    recStack[idx]=false;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    vector<bool> visited(V), recStack(V);
    for(int i=0;i<V;i++){
        visited[i]=false;
        recStack[i]=false;
    }
    for(int i=0;i<V;i++){
        if(dfs(adj,i,visited,recStack))
            return true;
    }
    return false;
}
