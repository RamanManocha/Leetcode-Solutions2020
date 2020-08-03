#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool dfs(int i, bool visited[], vector <int>adj[], bool callvis[]) {
    visited[i] = true;
    callvis[i] = true;
    for(auto it=adj[i].begin(); it!=adj[i].end(); it++) {
        if(!visited[*it]) {
            if(dfs(*it,visited,adj,callvis)) return true;
        }
        else if(callvis[*it]) return true;
    }
    callvis[i] = false;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    int i;
    bool visited[V];
    bool callvis[V];
    memset(visited,0,sizeof(visited));
    memset(callvis,0,sizeof(callvis));
    for(i=0; i<V; i++) {
        if(!visited[i] && dfs(i,visited,adj,callvis))
            return 1;
    }
    return 0;
}

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
