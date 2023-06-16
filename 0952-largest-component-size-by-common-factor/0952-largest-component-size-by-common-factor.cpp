class DisjointSet {
    public: 
    vector<int> rank, parent;
    DisjointSet(int n) {
        for(int i = 0; i < n; i++) {
            parent.push_back(i);
            rank.push_back(1);
        }
    }
    int findParent(int node) {
        return (node==parent[node]) ? 
            node : parent[node]=findParent(parent[node]);
    }
    void unite(int u, int v) {
        int up = findParent(u);
        int vp = findParent(v);
        if(up != vp) {
            if(rank[up] < rank[vp]) {
                rank[vp] += rank[up];
                parent[up] = vp;
            }
            else if(rank[up] > rank[vp]) {
                rank[up] += rank[vp];
                parent[vp] = up;
            }
            else {
                rank[vp] += rank[up];
                parent[up] = vp; 
            }
        }
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>> factors;
        for(int i = 0; i < n; i++) {
            int num = nums[i];
            for(int j = 2; j * j <= num; j++) {
                if(num % j == 0) {
                    factors[j].push_back(i);
                    while(num % j == 0)
                        num /= j;
                }
            }
            if(num > 1) {
                factors[num].push_back(i);
            }
        }

        DisjointSet dsu(n);
        for(auto &it : factors) {
            vector<int> indices = it.second;     
            for(int i = 0; i < indices.size() - 1; i++) {
                dsu.unite(indices[i], indices.back());
            }
        }

        int largestComponent = 1;
        for(auto &curr_size : dsu.rank) {
            largestComponent = max(largestComponent, curr_size);
        }
        return largestComponent;
    }
};