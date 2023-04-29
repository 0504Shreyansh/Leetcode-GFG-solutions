// Use disjoint set to dynamically create the graph
class DisjointSet {
    public:
    vector<int> parent;
    DisjointSet(int n) {
        for(int i = 0; i <= n; i++)
            parent.push_back(i);
    }
    int findParent(int u) {
        return (u == parent[u]) ? u : parent[u] = findParent(parent[u]);
    }
    void unite(int u, int v) {
        parent[findParent(u)] = findParent(v);
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        
        // Push back the idx to not loose the track of their original position
        for(int i = 0; i < queries.size(); i++)
            queries[i].push_back(i);
        
        // Sort on the basis of the least weighted edges
        sort(begin(queries),end(queries),[&](auto&a, auto&b){return a[2]<b[2];});
        sort(begin(edgeList),end(edgeList),[&](auto&a, auto&b){return a[2]<b[2];});
        
        DisjointSet dsu(n);
        vector<bool> ans(queries.size());
        
        // Keep pointer i as global to keep creating the graph 
        // with the smaller wts as compared to query's weight limit
        int i = 0;
        for(auto q : queries) {
            int u = q[0], v = q[1], wt = q[2], idx = q[3];            
            // Create the graph with edges having smaller wts than the weight limit
            while(i < edgeList.size() && edgeList[i][2] < wt) {
                dsu.unite(edgeList[i][0], edgeList[i][1]);
                i++;
            }
            // One thing can be concluded here 
            // If they belong to one component, they will definitely have smaller wts
            //*Bcoz we are only inserting the edges which have samller than this wt limit.
            ans[idx] = (dsu.findParent(u) == dsu.findParent(v)) ? true : false;
        }
        return ans;
    }
};