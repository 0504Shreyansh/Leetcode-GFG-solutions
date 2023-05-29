//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct TrieNode {
    TrieNode *childNode[26];
    bool end = 0;
    bool containsKey(char ch) {
        return childNode[ch - 'A'] != NULL;
    }
    void put(char ch, TrieNode *root) {
        childNode[ch - 'A'] = root;
    }
    TrieNode* get(char ch) {
        return childNode[ch - 'A'];
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
    bool insert_key(string word, string pattern) {
        TrieNode *node = root;
        int j = 0, m = pattern.size();
        bool f = true;
        for(int i = 0; i < word.size(); i++) {
            if(word[i] >= 'A' && word[i] <= 'Z') {
                if(!node->containsKey(word[i])) {
                    node->put(word[i], node);
                }
                if(j < m && word[i] == pattern[j]) j++;
                else if(j == m && f != false) return true;
                else return false;
                node = node -> get(word[i]);
            }
        }
        return (j == m && f);
    }
};

class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        vector<string> ans;
        Trie *root = new Trie();
        for(auto it : Dictionary)
            if(root -> insert_key(it, Pattern))
                ans.push_back(it);
        if(ans.empty()) ans.push_back("-1");
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends