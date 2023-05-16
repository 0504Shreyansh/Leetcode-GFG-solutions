//{ Driver Code Starts
//Initial Template for C++

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
    void insert_key(string word) {
        TrieNode* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new TrieNode());
            }
            node->increasePrefix();
            node = node->get(word[i]); 
        }
        node->increaseEnd();
    }
    string findShortestUniquePrefix(string word) {
        TrieNode *node = root;
        for(int i = 0; i < word.size(); i++) {
            if(node->getPrefix()==1) {
                return word.substr(0, i);
            }
            node = node->get(word[i]);
        }
        return word;
    }
};


class Solution
{
    public:
    vector<string> findPrefixes(string arr[], int n)
    {
        vector<string> ans;
        Trie *root = new Trie();
        for(int i = 0; i < n; i++) {
            root -> insert_key(arr[i]);
        }
        for(int i = 0; i < n; i++) {
            ans.push_back(root->findShortestUniquePrefix(arr[i]));
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

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}

// } Driver Code Ends