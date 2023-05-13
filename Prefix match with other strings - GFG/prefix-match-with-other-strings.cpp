//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

struct TrieNode {
    TrieNode *childNode[26];
    int cntPrefix = 0;
    int cntEnd = 0;
    bool containsKey(char ch) {
        return childNode[ch - 'a'] != NULL;
    }
    void put(char ch, TrieNode *root) {
        childNode[ch - 'a'] = root;
    }
    TrieNode* get(char ch) {
        return childNode[ch - 'a'];
    }
    void increasePrefix() {
        cntPrefix++;
    }
    void decreasePrefix() {
        cntPrefix--;
    }
    void increaseEnd() {
        cntEnd++;
    }
    void decreaseEnd() {
        cntEnd--;
    }
    int getPrefix() {
        return cntPrefix;
    }
    int getEnd() {
        return cntEnd;
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
            node -> increasePrefix();
        }
        node->increaseEnd();
    }
    int countStartWith(string word) {
        TrieNode *node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->containsKey(word[i])) {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getPrefix();
    }
};


class Solution{   
public:
    int klengthpref(string arr[], int n, int k, string ss){    
        Trie *root = new Trie();
        for(int i = 0; i < n; i++)
            root -> insert_key(arr[i]);
        return root -> countStartWith(ss.substr(0, k));
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 

// } Driver Code Ends