//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);


// } Driver Code Ends

struct TrieNode {
    TrieNode* childNode[2];
    bool end = false;
    bool containsKey(int a) {
        return childNode[a] != NULL;
    }
    void put(int a, TrieNode* curr) {
        childNode[a] = curr;
    }
    TrieNode *get(int a) {
        return childNode[a];
    }
    void setEnd() {
        end = true;
    }
    void unsetEnd() {
        end = false;
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
    void insert(int *row, int col) {
        TrieNode *node = root;
        for(int i = 0; i < col; i++) {
            if(!node->containsKey(row[i])) {
                node->put(row[i], new TrieNode());
            }
            node = node->get(row[i]);
        }
        node->setEnd();
    }
    bool search(int *row, int col) {
        TrieNode *node = root;
        for(int i = 0; i < col; i++) {    
            node = node->get(row[i]);
        }
        bool ans = node->getEnd();
        node->unsetEnd();
        return ans;
    }
};

class Solution
{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
    {
        Trie *root = new Trie();
        for(int i = 0; i < row; i++) {
            root->insert(M[i], col);
        }

        vector<vector<int>> ans;
        for(int i = 0; i < row; i++) {
            vector<int> tmp;
            if(root->search(M[i], col)) {
                for(int j = 0; j < col; j++)
                    tmp.push_back(M[i][j]);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	Solution ob;
    	vector<vector<int>> vec = ob.uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

// } Driver Code Ends