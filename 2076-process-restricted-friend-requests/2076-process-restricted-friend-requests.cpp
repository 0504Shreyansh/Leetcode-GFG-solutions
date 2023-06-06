class DisjointSet {
    public :
    vector<int> rank;
    vector<int> parent;
    DisjointSet(int n) {
        for(int i = 0; i < n; i++) {
            rank.push_back(1);
            parent.push_back(i);
        }
    }
    int findParent(int node) {
        return (parent[node] == node) ? node : parent[node] = findParent(parent[node]);
    }
    void unite(int u, int v) {
        int up = findParent(u);
        int vp = findParent(v);
        if(up == vp) return ;
        if(rank[up] < rank[vp]) {
            parent[up] = vp;
        }
        else if(rank[vp] > rank[up]) {
            parent[vp] = up;
        }
        else {
            rank[vp]++;
            parent[up] = vp;
        }
    }
};

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        DisjointSet dsu(n);
        vector<bool> ans;
        for(int i = 0; i < requests.size(); i++) {
            int parent1 = dsu.findParent(requests[i][0]);
            int parent2 = dsu.findParent(requests[i][1]);
            // Check if the request are restricted or not.
            bool canBeFriends = true;
            for(int j = 0; j < restrictions.size(); j++) {
                int parentRes1 = dsu.findParent(restrictions[j][0]);
                int parentRes2 = dsu.findParent(restrictions[j][1]);
                // Found restricted
                if((parent1 == parentRes1 && parent2 == parentRes2) || (parent1 == parentRes2 && parent2 == parentRes1)) {
                    canBeFriends = false;
                    break;
                }
            }
            // They can now be friends
            if(canBeFriends) {
                dsu.unite(requests[i][0], requests[i][1]);
                ans.push_back(true);
            }
            else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};