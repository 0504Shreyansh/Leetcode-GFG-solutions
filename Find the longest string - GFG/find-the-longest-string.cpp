//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

struct TrieNode {
    TrieNode *childNode[26];
    bool isEnd = false;
    bool containsKey(char ch) {
        return childNode[ch - 'a'] != NULL;
    }
    void put(char ch, TrieNode *root) {
        childNode[ch - 'a'] = root;
    }
    TrieNode* get(char ch) {
        return childNode[ch - 'a'];
    }
    bool getEnd() {
        return isEnd;
    }
    void setEnd() {
        isEnd = true;
    }
    void desetEnd() {
        isEnd = false;
    }
};

class Trie {
    public:
    TrieNode* root;    
    string ans = "";
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
    // Deletes a key
    bool delete_key(string word) {
        TrieNode *node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        node->desetEnd();
        return true;
    }
    // Checks if any string starts with the prefix
    bool startsWith(string word) {
        TrieNode *node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return true;
    }

    int countWordsEqualTo(string word) {
        TrieNode *node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->containsKey(word[i])) {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getEnd();
    }
    
    void longest(string word, string &ans){
        TrieNode* cur = root;
        int len = 0;
        // cout << word << ' ' << len << endl;
        for(int i = 0; i < word.size(); i++) {
            // cout << cur->getEnd() << endl;
            cur = cur->get(word[i]);
            if(!cur->getEnd()) {
                return ;
            }
            len++;
        }
        if(ans.size() == len) {
            ans = min(ans, word);
        }
        else if(ans.size() < len) {
            ans = word;
        } 
    }
};


class Solution {
    public:
    string longestString(vector<string> &words)
    {
        Trie *root = new Trie();
        for(auto str : words)
            root -> insert_key(str);
            
        // sort(begin(words),end(words),[&](auto &a, auto &b) {
        //     if(a.size()==b.size()) return a < b;
        //     return a.size() < b.size();
        // });
        string ans = "";
        for(int i = 0; i < words.size(); i++) {
            root->longest(words[i], ans);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends