//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{

    public:
    Node* homeNode;
    unordered_map<Node*,Node*> nodeToParent;
    void inorder(Node* root, int home) {
        if(!root) return ;
        inorder(root->left, home);
        inorder(root->right, home);
        if(root->data==home) homeNode = root;
        if(root->left) nodeToParent[root->left] = root;
        if(root->right) nodeToParent[root->right] = root;
    }
    int solve(Node* root, Node* homeNode, int k) {
        int ans = 0;
        queue<Node*> Q({homeNode});
        unordered_map<Node*,int> vis;
        k++;
        vis[homeNode] = 1;
        while(k--) {
            int size = Q.size();
            for(int i = 0; i < size; i++) {
                Node* cur = Q.front();
                Q.pop();
                ans += cur->data;
                if(cur->left && !vis[cur->left]) {
                    vis[cur->left] = 1;
                    Q.push(cur->left);
                }
                if(cur->right && !vis[cur->right]) {
                    vis[cur->right] = 1;
                    Q.push(cur->right);
                }
                if(nodeToParent[cur] && !vis[nodeToParent[cur]]) {
                    vis[nodeToParent[cur]] = 1;
                    Q.push(nodeToParent[cur]);
                }
            }
        } 
        return ans;
    }
    int ladoos(Node* root, int home, int k)
    {
        inorder(root, home);
        nodeToParent[root] = NULL;
        return solve(root, homeNode, k);
    }


};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends