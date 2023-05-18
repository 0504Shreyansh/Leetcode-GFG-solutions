//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

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
    void increaseEnd() {
        cntEnd++;
    }
    int getEnd() {
        return cntEnd;
    }
    void desetEnd() {
        cntEnd = 0;
    }
};

class Trie {
    private:
    TrieNode* root;
    public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode *node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new TrieNode());
            }
            node = node->get(word[i]);
        }
        node->increaseEnd();
    }
    void search(string word, int &len, string &ans) {
        TrieNode *node = root;
        for(int i = 0; i < word.size(); i++) {
            node = node -> get(word[i]);
        }
        int c = node -> getEnd();
        node -> desetEnd();
        if(c >= len) {
            len = c;
            ans = word;
        }
    }
};

class Solution
{
    public:
    //Function to find most frequent word in an array of strings.
    string mostFrequentWord(string arr[], int n) 
    {
        Trie *root = new Trie();
        for(int i = 0; i < n; i++) {
            root -> insert(arr[i]);
        }
        int len = 0;
        string ans = "";
        for(int i = 0; i < n; i++) {
            root -> search(arr[i], len, ans);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.mostFrequentWord(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends