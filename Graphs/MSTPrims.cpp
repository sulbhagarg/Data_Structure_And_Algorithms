/* Given a weighted, undirected and connected graph. The task is to find the sum of weights of the edges of the Minimum Spanning Tree. */

int findKey(int *key, bool *visited, int V){
    int min=INT_MAX,min_index;
    for(int i=0;i<V;i++)
        if(!visited[i] && key[i]<min)
            min=key[i],min_index=i;
    return min_index;
}
int spanningTree(int V, int E, vector<vector<int>> &graph) {
    // code here
    bool visited[V];
    int key[V];
    for(int i=0;i<V;i++)
        visited[i]=false,key[i]=INT_MAX;
    int ans=0,count=0;
    key[0]=0;
    while(count<V){
        int j=findKey(key,visited,V);
        visited[j]=true;
        for(int i=0;i<V;i++){
            if(!visited[i] && graph[j][i]!=INT_MAX && graph[j][i]<key[i]){
                key[i]=graph[j][i];
            }
        }
        count++;
    }
    for(int i=0;i<V;i++)
        ans+=key[i];
    return ans;
}
