struct TrieNode {
    TrieNode* childNode[2];
    bool end = 0;
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
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node -> containsKey(bit)) {
                node -> put(bit);
            }
            node = node -> get(bit);
        }
        node -> setEnd();
    }
    int solve(int num) {
        TrieNode* node = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node -> containsKey(!bit)) {
                node = node -> get(!bit);
                if (!bit) ans |= (1 << i);
            } else {
                node = node -> get(bit);
                if (bit) ans |= (1 << i);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* root = new Trie();
        for (auto &it : nums) {
            root -> insert(it);
        }
        int maxXor = 0;
        for (auto &it : nums) {
            maxXor = max(maxXor, it ^ root -> solve(it));
        }
        return maxXor;
    }
};