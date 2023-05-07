//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);

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
    	vector<vector<int>> vec = uniqueRow(a,n,m);
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

struct TrieNode {
    TrieNode *childNode[2];
    bool isEnd = false;
    bool containsKey(int a) {
        return childNode[a] != NULL;
    }
    void put(int a, TrieNode* root) {
        childNode[a] = root;
    }
    TrieNode* get(int a) {
        return childNode[a]; 
    }
    bool getEnd() {
        return isEnd;
    }
    void setEnd() {
        isEnd = true;
    }
};

class Trie {
    public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    void insert(int row[], bool &toPush, int n) {
        TrieNode* node = root;
        for(int i = 0; i < n; i++) {
            if(!node->containsKey(row[i])) {
                node -> put(row[i], new TrieNode());
            }
            node = node -> get(row[i]);
        }
        if(node -> getEnd()) {
            return ;
        }
        node -> setEnd();
        toPush = true;
    }
};


/*You are required to complete this function*/
vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
    vector<vector<int>> ans;
    Trie *root = new Trie();
    for(int i = 0; i < row; i++) {
        bool toPush = false;
        root -> insert(M[i], toPush, col);
        if(toPush) {
            vector<int> tmp;
            for(int j = 0; j < col; j++)
                tmp.push_back(M[i][j]);
            ans.push_back(tmp);
        }
    }
    return ans;
}