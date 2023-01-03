//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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


int printKDistantfromLeaf(Node* node, int k);

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


int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s, ks;
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, ks);
        int k=stoi(ks);
        cout<<printKDistantfromLeaf(root, k)<<endl;
    }
    return 0;
}


// } Driver Code Ends


//Node Structure
/*struct Node
{
	int key;
	Node *left, *right;
};*/


//Function to return count of nodes at a given distance from leaf nodes.
void getLeafNodes(Node* root, vector<Node*> &leafs) {
    if(!root) return;
    getLeafNodes(root->left,leafs);
    if(!root->left && !root->right)
        leafs.push_back(root);
    getLeafNodes(root->right,leafs);
}
void createMap(Node* root, map<Node*,Node*> &mp) {
    queue<Node*> q;
    q.push(root);
    mp[root] = NULL;
    while(q.size()) {
        int n = q.size();
        for(int i=0;i<n;i++) {
            Node* p = q.front(); q.pop();
            if(p->left) {
                q.push(p->left);
                mp[p->left] = p;
            }
            if(p->right) {
                q.push(p->right);
                mp[p->right] = p;
            }
        }
    }
}
int printKDistantfromLeaf(Node* root, int k)
{
	vector<Node*> leafs;
    map<Node*,Node*> mp;
    createMap(root,mp);
	getLeafNodes(root,leafs);
	map<int,set<Node*>> vis;
	queue<pair<int,Node*>> q;
	
	int ans = 0;
	for(int i=0;i<leafs.size();i++) {
	    Node* p = leafs[i];
	    q.push({0,p});
	}
	while(q.size()) {
	    int n = q.size();
	    for(int i=0;i<n;i++) {
	        int dist = q.front().first;
	        Node* p = q.front().second;
	        q.pop();
	        vis[dist].insert(p);
	        if(mp[p]) {
	
	            q.push({dist+1,mp[p]});
	        }
	    }
	}
	for(auto i : vis) {
	    if(i.first==k) return i.second.size();
	}
	return ans;
}