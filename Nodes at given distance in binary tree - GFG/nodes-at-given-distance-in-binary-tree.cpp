//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
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
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:
    Node* createMap(Node* root, map<Node*,Node*> &mp, int target) {
        queue<Node*> q;
        q.push(root);
        mp[root] = NULL;
        Node* targetNode = NULL;
        while(q.size()) {
            int n = q.size();
            for(int i=0;i<n;i++) {
                Node* p = q.front(); 
                q.pop();
                if(p->data==target) {
                    targetNode = p;
                }
                if(p->left) {
                    mp[p->left] = p;
                    q.push(p->left);
                }
                if(p->right) {
                    mp[p->right] = p;
                    q.push(p->right);
                }
            }
        }
        
        return targetNode;
    }
    vector<int> solve(Node* targetNode, int k, map<Node*,Node*> mp) {
        vector<int> ans;
        queue<pair<int,Node*>> q;
        q.push({0,targetNode});
        map<Node*,bool> vis;
        vis[targetNode] = true;
        while(q.size()) {
            int n = q.size();
            bool f = false;
            for(int i=0;i<n;i++) {
                auto j = q.front(); q.pop();
                int dist = j.first;
                Node* p = j.second;
                if(dist==k) {
                    f = true;
                    ans.push_back(p->data);
                }
                if(p->left && !vis[p->left]) {
                    vis[p->left] = true;
                    q.push({dist+1,p->left});
                }
                if(p->right && !vis[p->right]) {
                    vis[p->right] = true;
                    q.push({dist+1,p->right});
                }
                if(mp[p] && !vis[mp[p]]) {
                    vis[mp[p]] = true;
                    q.push({dist+1,mp[p]});
                }
            }
            if(f) return ans;
        }
        
        return ans;
    }
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        map<Node*,Node*> mp;
        Node* targetNode = createMap(root,mp,target);
        // vector<int> ans;
        // for(auto i:mp) {
        //     cout<<i.first->data<<' '<<i.second->data<<endl;
        // }
        
        
        vector<int> ans = solve(targetNode,k,mp);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends