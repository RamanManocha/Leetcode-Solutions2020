261. Graph Valid Tree


Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

Example 1:

Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
Output: true
Example 2:

Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
Output: false




   class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    vector<int> parent;
    void connect(int a, int b){
        int x=find(a);
        int y=find(b);
        if(x!=y){
            parent[y]=x;
        }
    }
    int find(int x){
        int j=x;
        while(j!=parent[j]) j=parent[j];
        int tmp;
        // paht compress
        while(x!=parent[x]){
            tmp=parent[x];
            parent[x]=j;
            x=parent[x];
        }
        return j;
    }
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
         parent.resize(n+1);
         for(int i=1;i<=n;i++) parent[i]=i;
         for(int i=0;i<edges.size();i++){
             int x=edges[i][0];
             int y=edges[i][1];
             if(find(x)!=find(y)) connect(x,y);
             else return false;
         }
         return edges.size()==n-1;
    }
};
