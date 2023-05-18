//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

struct TrieNode {
    TrieNode *childNode[2];
    bool containsKey(int a) {
        return childNode[a] != NULL;
    }
    void put(int a, TrieNode* root) {
        childNode[a] = root;
    }
    TrieNode* get(int a) {
        return childNode[a];
    }
};

class Trie {
    TrieNode* root;
    public:
    Trie() {
        root = new TrieNode();
    }
    void insert_key(int x) {
        TrieNode *node = root;
        for(int i = 31; i >= 0; i--) {
            int mask = (x >> i) & 1;
            if(!node->containsKey(mask)) {
                node->put(mask, new TrieNode());
            }
            node = node->get(mask);
        }
    }
    int findMaxXor(int x) {
        int maxXor = 0;
        TrieNode *node = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if(!node->containsKey(bit) && !node->containsKey(!bit)) {
                return 1e5;
            }
            if(node->containsKey(bit)) {
                node = node -> get(bit);
            }
            else {
                node = node -> get(!bit);
                maxXor += pow(2, i);
            }
        }
        return maxXor;
    }
};

class Solution{   
public:
    int minxorpair(int N, int arr[]){    
        Trie *root = new Trie();
        int ans = 1e5;
        for(int i = 0; i < N; i++) {
            ans = min(ans, root->findMaxXor(arr[i]));
            root -> insert_key(arr[i]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.minxorpair(N, arr) << endl;
    }
    return 0; 
} 

// } Driver Code Ends