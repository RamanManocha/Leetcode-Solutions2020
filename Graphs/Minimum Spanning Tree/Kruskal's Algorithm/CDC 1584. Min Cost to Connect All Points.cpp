

https://www.youtube.com/watch?v=E8cDVhmkKSQ&ab_channel=AHTechAHTech



1584. Min Cost to Connect All Points
Medium

441

26

Add to List

Share
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

 

Example 1:



Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation:

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18
Example 3:

Input: points = [[0,0],[1,1],[1,0],[-1,1]]
Output: 4
Example 4:

Input: points = [[-1000000,-1000000],[1000000,1000000]]
Output: 4000000
Example 5:

Input: points = [[0,0]]
Output: 0
 

Constraints:

1 <= points.length <= 1000
-106 <= xi, yi <= 106
All pairs (xi, yi) are distinct.







Obviously, it is a variation of the Kruskal's algorithm.
Initially, I got TLE too, so I thought of merging the smaller set into the larger set (by keep tracking the size of the sets) and then that passed all the test cases.
( SideNote: In the sorting step, I feel it is an overkill to sort the vector. With a hashMap of the values, perhaps we can do better. )
My solution is as follows:






class Solution {
public:
    struct info{ // This saves the distance info
        int ind1;
        int ind2;
        int dist;
    };
    vector<int> parent;
    vector<int> len;
    int fiind(int a){
        if (a == parent[a])
            return a;
        parent[a] = fiind(parent[a]);
        return parent[a];
    }
    void uniion(int a, int b){
        a = fiind(a);
        b = fiind(b);
        if (a==b)
            return;
        if (len[b]<len[a]){ // Optimize the merge of the two sets
            parent[b] = a;
            len[a] += len[b];
        }else{
            parent[a] = b;
            len[b] += len[a];
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        parent.resize(points.size(),0);
        len.resize(points.size(),0);
        for (int i = 0;i<points.size();i++){
            parent[i] = i;
            len[i] = 1;
        }
        vector<info> vec;
        int dist;
        info temp;
        for (int i = 0;i<points.size()-1;i++){
            for (int j = i+1;j<points.size();j++){
                dist = (abs)(points[i][0]-points[j][0]) + (abs)(points[i][1]-points[j][1]);
                temp.ind1 = i;
                temp.ind2 = j;
                temp.dist = dist;
                vec.push_back(temp);
            }   
        }
        sort(vec.begin(),vec.end(),[](const info a,const info b){
                                        return a.dist < b.dist;
                                    });
        int cost = 0;
        int count = 1;
        for (int i = 0;i<vec.size();i++){
            if (count==points.size())
                break;
            if (fiind(vec[i].ind1)==fiind(vec[i].ind2))
                continue;
            cost += vec[i].dist;
            count++;
            uniion(parent[vec[i].ind1],parent[vec[i].ind2]);
        }
        return cost;
    }
};










