struct TrieNode {
    TrieNode *childNode[26];
    int end = 0;
    bool containsKey(char ch) {
        return childNode[ch - 'a'] != NULL;
    }
    void put(char ch, TrieNode *root) {
        childNode[ch - 'a'] = root;
    }
    TrieNode* get(char ch) {
        return childNode[ch - 'a'];
    }
    void setEnd() {
        end = true;
    }
    bool getEnd() {
        return end;
    }
};

class Trie {
    private:
    TrieNode* root;
    public:
    Trie() {
        root = new TrieNode();
    }
    // Inserts a key
    void insert_key(string word) {
        TrieNode *node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new TrieNode());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    void search(string word) {
        TrieNode *node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->containsKey(word[i])) {
                node->setEnd();
                return ;
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    string longestPrefix(string word) {
        TrieNode *node = root;
        string curr = "";
        for(int i = 0; i < word.size(); i++) {
            if(node->getEnd()) {
                break;
            } else {
                curr += word[i];
            }
            node = node->get(word[i]);
        }
        return curr;
    }
};


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        Trie *root = new Trie();
        root->insert_key(strs[0]);
        for(auto &it : strs)
            root->search(it);   // Adjust the end variable
        return root->longestPrefix(strs[0]);
    }
};