//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct TrieNode {
    TrieNode *childNode[26];
    bool isEnd = false;
    bool containsKey(char ch) {
        return childNode[ch - 'A'] != NULL;
    }
    void put(char ch, TrieNode* root) {
        childNode[ch - 'A'] = root;
    }
    TrieNode *get(char ch) {
        return childNode[ch - 'A'];
    }
    void setEnd() {
        isEnd = true;
    }
    bool getEnd() {
        return isEnd;
    }
};

class Trie {
    TrieNode *root;
    public:  
    Trie() {
        root = new TrieNode();
    }
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
                else if(j == m && f != false) f = true;
                else f = false;
                node = node -> get(word[i]);
            }
        }
        node -> setEnd();
        if(!f) return false;
        return (j == m);
    }
};

class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        vector<string> ans;
        Trie *root = new Trie();
        for(auto s : Dictionary) {
            if (root -> insert_key(s, Pattern)) {
                ans.push_back(s);
            }
        }
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