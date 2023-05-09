//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

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
        // cout<<word<<"->";
        TrieNode *node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new TrieNode());
            }
            node = node->get(word[i]);
            node -> increasePrefix();
            // cout<<node->getPrefix()<<' ';

        }
        node->increaseEnd();
        // cout<<endl;
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
        node->decreaseEnd();
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
    void insert(string word, int &cnt, string &ans) {
        TrieNode *node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new TrieNode());
            }
            node = node->get(word[i]);
        }
        node->increaseEnd();
        int c = node->getEnd();
        if(c > cnt) {
            ans = word;
            cnt = c;
        }
        else if(c == cnt) {
            ans = word;
        }
    }
};

class Solution{
public:
    vector<int> prefixCount(int n, int q, string li[], string query[])
    {
        Trie *root = new Trie();
        for(int i = 0; i < n; i++) {
            root -> insert_key(li[i]);
        } 
        vector<int> ans(q);
        for(int i = 0; i < q; i++) {
            ans[i] = root -> countStartWith(query[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int Q, N, i = 0, x;
	    cin>>N;
	    string s;
	    string li[N];
	    for(int i = 0;i < N;i++)
	        cin>>li[i];
	    cin>>Q; 
	    x = Q;
	    string query[Q];
	    while(Q--){
	        cin>>s;
	        query[i++] = s;
	    }
	    
	    Solution ob;
	    vector<int> ans = ob.prefixCount(N, x, li, query);
	    for(auto i: ans) 
	        cout<<i<<"\n";
    }
    return 0;
}
// } Driver Code Ends