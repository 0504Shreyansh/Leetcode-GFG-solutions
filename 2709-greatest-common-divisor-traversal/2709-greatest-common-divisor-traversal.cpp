class Solution {
private:
    vector<int> par;
    int find(int u) {
        return (par[u] == u) ? u : par[u] = find(par[u]);
    }
    void unite(int u, int v) {
        par[find(u)] = par[find(v)] = min(find(u), find(v));
    }
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) par.push_back(i);
        map<int, vector<int>> idxs;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            for (int j = 2; j * j <= num; j++) {
                if (num % j == 0) {
                    idxs[j].push_back(i);
                    while (num % j == 0) num /= j;
                }
            }
            if (num > 1) idxs[num].push_back(i);
        }
        
        for (auto &it : idxs) {
            for (int &idx : it.second) {
                unite(it.second[0], idx);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += find(i) == i;
        }
        return (ans == 1);
    }
};