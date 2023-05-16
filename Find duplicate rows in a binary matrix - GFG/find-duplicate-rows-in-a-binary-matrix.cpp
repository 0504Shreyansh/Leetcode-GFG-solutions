//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

struct TrieNode {
    TrieNode *childNode[2];
    bool isEnd = false;
    int storeIndex = -1;
    int pref = 0;
    bool containsKey(int a) {
        return childNode[a] != NULL;
    }
    TrieNode* get(int a) {
        return childNode[a];
    }
    void put(int a, TrieNode* root) {
        childNode[a] = root;
    }
    void setEnd() {
        isEnd = true;
    }
    bool getEnd() {
        return isEnd;
    }
    void setPref() {
        pref++;
    }
    bool getPref() {
        return pref;
    }
    void setIndex(int index) {
        storeIndex = index;
    }
    int getIndex() {
        return storeIndex;
    }
};

class Trie {
    TrieNode *root;
    public:
    Trie() {
        root = new TrieNode();
    }
    bool insert_key(vector<int>& nums, int index) {
        TrieNode *node = root;
        for(int i = 0; i < nums.size(); i++) {
            if(!node->containsKey(nums[i])) {
                node -> put(nums[i], new TrieNode());
            }
            node = node -> get(nums[i]);
            node->setPref();
        }
        node -> setEnd();
        
        if(node->getIndex() == -1) {
            node->setIndex(index);
            return false;
        }
        return true;
    }
};


class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> matrix, int M, int N) 
    { 
        int n = matrix.size();
        Trie *root = new Trie();
        vector<int> ans;
    
        for (int i = 0; i < n; i++) {
            if (root -> insert_key(matrix[i], i)) {
                ans.push_back(i);
            }
        }
    
        return ans;
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



// } Driver Code Ends