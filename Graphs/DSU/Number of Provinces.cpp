
47. Number of Provinces
Medium

2557

168

Add to List

Share
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
 

Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]


dfs approach:




Connected Components in a bidirectional Graph
As given in the question, we have n nodes. So we will make a visited array for n nodes. then we will start with one node, and mark all its connected nodes as visited=true. So we will count only how many times we have to start this process. that will be our answer.

int findCircleNum(vector<vector<int>>& M) {
	int n=M.size(),ans=0;
	if(n==0) return 0;

	vector<bool>vis(n,false);

	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			ans++;
			dfs(M,vis,i);
		}
	}
	return ans;
}

void dfs(vector<vector<int>>& M, vector<bool>& vis, int i)
{
	vis[i]=true;
	for(int j=0;j<M.size();j++)
		if(M[i][j]==1 && !vis[j])
			dfs(M,vis,j);
}






class Solution {
public:
    int parent[201];
    
    int findCircleNum(vector<vector<int>>& M) {
        int i, j, groups = 0, n = M.size();
        make_set(n);
          
        for(i = 0; i < n; i++) {
            for(j = i + 1; j < n; j++) {
                if(M[i][j])
                    union_sets(i, j);
            }
        }
        
        for(i = 0; i < n; i++) {
            if(i == parent[i])
                groups++;
        }
        
        return groups;
    }

private:
    void make_set(int n) {
        for(int i = 0; i < n; i++) 
            parent[i] = i;
    }
    
    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
            parent[b] = a;
    }
};


class Solution {
public:
    vector<int>friends;
 	
    int find(int i)
    {
        return friends[i]==i?i:find(friends[i]);
    }
    int findCircleNum(vector<vector<int>>& M) {
        
        int n = M.size();
        friends.resize(n);
        for(int i = 0; i < n; i++){
            friends[i] = i;
        }
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(M[i][j]==1)
                {
                    int x = find(i);
                    int y = find(j);
                    if(x != y)
                    {
                        friends[y] = x;
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0;i < n ;i++)
        {
            if(friends[i]==i)
                ans++;
        }
        return ans;
    }
};










// class Solution {
// public:
//     int findCircleNum(vector<vector<int>>& M) {
//         if (M.empty()) return 0;
//         int n = M.size();

//         vector<int> leads(n, 0);
//         for (int i = 0; i < n; i++) { leads[i] = i; }   // initialize leads for every kid as themselves

//         int groups = n;
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {   // avoid recalculate M[i][j], M[j][i]
//                 if (M[i][j]) {
//                     int lead1 = find(i, leads);
//                     int lead2 = find(j, leads);
//                     if (lead1 != lead2) {       // if 2 group belongs 2 different leads, merge 2 group to 1
//                         leads[lead1] = lead2;
//                         groups--;
//                     }
//                 }
//             }
//         }
//         return groups;
//     }

// private:
//     int find(int x, vector<int>& parents) {
//         return parents[x] == x ? x : find(parents[x], parents);
//     }
// };
