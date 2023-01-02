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
    Node* createMap(Node* root, unordered_map<Node*,Node*> &mp, int target) {
        Node* ans = NULL;
        queue<Node*> q;
        q.push(root);
        mp[root] = NULL;
        while(q.size()) {
            int n = q.size();
            for(int i=0;i<n;i++) {
                Node* p = q.front(); q.pop();
                if(p->data == target) 
                    ans = p;
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
        return ans;
    }
    int getSum(Node* targetNode, unordered_map<Node*,Node*> mp, int k) {
        int sum = targetNode->data;
        queue<pair<int,Node*>> q;
        q.push({0,targetNode});
        unordered_map<Node*,bool> vis;
        vis[targetNode] = true;
        while(q.size()) {
            int n = q.size();
            for(int i=0;i<n;i++) {
                int dist = q.front().first;
                Node* p = q.front().second;
                q.pop();
                if(dist>=k) return sum;
                if(p->left && !vis[p->left]) {
                    if(dist<k) sum += p->left->data;
                    vis[p->left] = true;
                    q.push({dist+1,p->left});
                }
                if(p->right && !vis[p->right]) {
                    if(dist<k) sum += p->right->data;
                    vis[p->right] = true;
                    q.push({dist+1,p->right});
                }
                if(mp[p] && !vis[mp[p]]) {
                    if(dist<k) sum += mp[p]->data;
                    vis[mp[p]] = true;
                    q.push({dist+1,mp[p]});
                }
            } 
        }
        return sum;
    }
    int sum_at_distK(Node* root, int target, int k)
    {
        unordered_map<Node*,Node*> mp;
        Node* targetNode = createMap(root,mp,target);
        int sum = getSum(targetNode,mp,k);
        return sum;
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
        
        int target,k;
        cin>> target >> k;
        getchar();
        
        Solution ob;
        cout<< ob.sum_at_distK(root,target,k) << endl;
    }
	return 0;
}


// } Driver Code Ends