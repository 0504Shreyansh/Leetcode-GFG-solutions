class DSU {
    vector<int> rank;
    vector<int> parent;
public:
    DSU(int n) {
        rank.resize(26);
        parent.resize(26);
        for (int i = 0; i < 26; ++i)
            parent[i] = i;
    }
    int findPar(int c) {
        return (parent[c] == c) ? c : (parent[c] = findPar(parent[c]));
    }
    void unite(int a, int b) {
        a = findPar(a);
        b = findPar(b);
        if (a != b) {
            if (rank[a] < rank[b]) {
                parent[a] = b;
            } else if (rank[a] > rank[b]) {
                parent[b] = a;
            } else {
                rank[b]++;
                parent[a] = b;
            }
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU obj(26);
        for (auto &it : equations) {
            if (it[1] == '=') {
                obj.unite(it[0]-'a', it[3]-'a');
            }
        }
        for (auto &it : equations) {
            if (it[1] == '!') {
                if (obj.findPar(it[0] - 'a') == obj.findPar(it[3] - 'a')) {
                    return false;
                }
            }
        }
        return true;
    }
};