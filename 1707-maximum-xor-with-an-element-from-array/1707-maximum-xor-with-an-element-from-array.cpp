struct TrieNode {
    TrieNode* childNode[2];
    bool end = false;
    bool containsKey(int a) {
        return childNode[a] != nullptr;
    }
    void put(int a) {
        childNode[a] = new TrieNode();
    }
    TrieNode* get(int a) {
        return childNode[a];
    }
    void setEnd() {
        end = 1;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(int num) {
        TrieNode *node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node -> containsKey(bit)) {
                node -> put(bit);
            }
            node = node -> get(bit);
        }
        node -> setEnd();
    }
    int solve(int x, int m) {
        TrieNode* node = root;
        int num = 0;
        for (int i = 31; i >= 0; i--) {
            int curBit = (x >> i) & 1;
            if (node -> containsKey(!curBit)) {
                node = node -> get(!curBit);
                if (!curBit) num |= (1 << i);
            } else if (node -> containsKey(curBit)) {
                node = node -> get(curBit);
                if (curBit) num |= (1 << i);
            } else {
                return -1;
            }
        }
        return num;
    }  
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        // sort so that only less values than m are always considered for each query
        sort(begin(nums),end(nums));
        for (int i = 0; i < queries.size(); i++) {
            queries[i].push_back(i);
        }
        sort(begin(queries),end(queries),[&](auto &a, auto &b) {
            return a[1] < b[1];
        });
        Trie* root = new Trie();
        int i = 0;
        int n = nums.size();
        vector<int> ans(queries.size(), -1);
        for (auto &q : queries) {
            int x = q[0];
            int m = q[1];
            int index = q[2];
            // insert all smaller values
            while (i < n && nums[i] <= m) {
                root -> insert(nums[i++]);
            }
            int num = root -> solve(x, m);
            // if some number from nums is found -> xor with x, else store -1
            if (num != -1) {
                ans[index] = (x ^ num);
            }
        }
        return ans;
    }
};