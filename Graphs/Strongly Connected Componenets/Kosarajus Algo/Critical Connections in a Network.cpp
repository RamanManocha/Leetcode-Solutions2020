

1192. Critical Connections in a Network
Hard

2072

109

Add to List

Share
There are n servers numbered from 0 to n-1 connected by undirected server-to-server connections forming a network where connections[i] = [a, b] represents a connection between servers a and b. Any server can reach any other server directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some server unable to reach some other server.

Return all critical connections in the network in any order.

 

Example 1:



Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
 

Constraints:

1 <= n <= 10^5
n-1 <= connections.length <= 10^5
connections[i][0] != connections[i][1]
There are no repeated connections.








class Solution {
public:
    struct vertex{
        int time, lowpoint;
    };
    vector<vertex>visited;
    unordered_map<int, vector<int> > graph;
    int timestamp = 1;
    vector<vector<int>> ans;
 
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        visited.resize(n);
        //prepare the graph
        for(auto edge: connections){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        //cover the case of multiple disconnected components
        for(int i=0; i<n;i++)
            if(visited[i].time == 0)
                dfs(i, -1);
        return ans;
    }
    
    void dfs(int v, int parent){
        visited[v].time = timestamp;
        visited[v].lowpoint = timestamp;
        timestamp++;
        for (auto neigh: graph[v]) {
            if (neigh == parent) //ignore the parent of current node
                continue;
            if (visited[neigh].time == 0) //dfs the neighbors
                dfs(neigh, v);
            // this is the most important part
            // 1. Save the current node's "minimum rank" reachable (Why? See explanation in the article)
            // 2. If neighbor's rank is less than the discover time of current node, add the edge as a critical connection
            visited[v].lowpoint = min(visited[v].lowpoint, visited[neigh].lowpoint);
            if(visited[neigh].lowpoint > visited[v].time){
                ans.push_back({v, neigh});
            }
        }
    }
};
