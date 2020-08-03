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









// Python approach:

graph = {0:[1,2], 1:[2], 2:[3], 3:[3]}
vertices = [0,1,2,3]

visited = [0]
recStk = [0]

  
"""  

def cycleUtil(graph,visited, recStk,v):
  visited.append(v)
  recStk.append(v)
  
  if v in graph:
    for n in graph[v]:
      if n in recStk:
        return True
      
      if n not in visited:
        retval = cycleUtil(graph, visited, recStk,n)
        if retval:
          return True
  recStk.pop()
  return False


def isCyclic(graph, vertices):
  visited = []
  recStk =[]
  
  for v in vertices:
    if v not in visited:
      retval = cycleUtil(graph,visited, recStk, v)
      if retval:
        return True
  return False
  
  
  
graph = {0:[1,2], 1:[2], 2:[3], 3:[3]}
vertices = [0,1,2,3]

print(isCyclic(graph,vertices))



