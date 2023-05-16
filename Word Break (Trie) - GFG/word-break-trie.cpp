//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

struct TrieNode {
    TrieNode *childNode[26];
    bool isEnd = false;
    bool containsKey(char ch) {
        return childNode[ch - 'a'] != NULL;
    }
    TrieNode* get(char ch) {
        return childNode[ch - 'a'];
    }
    void put(char ch, TrieNode* root) {
        childNode[ch - 'a'] = root;
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
    void insert_key(string word) {
        TrieNode *node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->containsKey(word[i])) {
                node -> put(word[i], new TrieNode());
            }
            node = node -> get(word[i]);
        }
        node -> setEnd();
    }
    bool search_key(string A) {
        TrieNode* node = root;
        for(int i = 0; i < A.size(); i++) {
            if(!node->containsKey(A[i])) {
                return false;
            }
            node = node->get(A[i]);
        }
        return node->getEnd();
    }
};

bool dfs(string &A, int i, Trie* root) {
    
    if(i==A.size())
        return true;
    
    for(int j = i; j < A.size(); j++) {
        if(root->search_key(A.substr(i, j-i+1)) && dfs(A, j+1, root)) {
            return true;
        }
    }
    return false;
}

class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    int wordBreak(string A, vector<string>& B) {
        int N = B.size();
        Trie *root = new Trie();
        for(int i = 0; i < N; i++) {
            root -> insert_key(B[i]);
        }
        return (dfs(A, 0, root)) ? true : false;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends