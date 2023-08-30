class DSU {
public:
    vector<int> size;
    vector<int> par;
    DSU(int n) {
        size.resize(n, 1);
        for (int i = 0; i < n; i++) 
            par.push_back(i);
    }
    int findPar(int u) {
        return (par[u] == u) ? u : par[u] = findPar(par[u]);
    }
    void unite(int u ,int v) {
        u = findPar(u);
        v = findPar(v);
        if (u != v) {
            if (size[u] <= size[v]) {
                size[v] += size[u];
                par[u] = v;
            } else {
                size[u] += size[v];
                par[v] = u;
            }
        }
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        unordered_map<int, vector<int>> factors;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            for (int j = 2; j * j <= num; j++) {
                if (num % j == 0) {
                    factors[j].push_back(i);
                    while (num % j == 0) 
                        num /= j;
                }
            }
            if (num > 1) factors[num].push_back(i);
        } 
        DSU obj(nums.size());
        for (auto &it : factors) {
            int par = it.second[0];
            for (int &j : it.second) {
                obj.unite(par, j);
            }
        }
        int largestComp = 1;
        for (auto &it : obj.size) {
            largestComp = max(largestComp, it);
        }
        return largestComp;
    }
};