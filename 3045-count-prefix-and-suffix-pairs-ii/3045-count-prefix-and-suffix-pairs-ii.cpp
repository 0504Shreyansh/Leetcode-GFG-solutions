struct TrieNode {
    TrieNode *children[40];
    long long cntEnd = 0;
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    // Inserts a key
    map<pair<char, char>, int> hash;
    int hashCount = 0;
    int generateHash(char a, char b) {
        if (hash.find({a, b}) != hash.end()) {
            return hash[{a, b}];
        }
        return hash[{a, b}] = hashCount++;
    }
    long long insert_key(string word) {
        long long count = 0;
        const int n = word.size();
        TrieNode *node = root;
        for (int i = 0; i < n; i++) {
            int val = generateHash(word[i], word[n - i - 1]);
            if (!node->children[val]) {
                node->children[val] = new TrieNode();
            }
            node = node->children[val];
            count += node->cntEnd;     
        }
        node->cntEnd++;
        return count;
    }
};

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        long long ans = 0;
        Trie* root = new Trie();
        for (auto &word : words) {
            ans += root->insert_key(word);
        }
        return ans;
    }
};