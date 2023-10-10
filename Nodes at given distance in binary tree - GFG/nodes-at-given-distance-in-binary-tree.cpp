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
    map<Node*, Node*> mp;
    Node* find(Node* root, int target) {
        Node* ans = NULL;
        mp[root] = NULL;
        queue<Node*> q({root});
        while (q.size()) {
            int size = q.size();
            while (size--) {
                Node* C = q.front();
                q.pop();
                if (C -> data == target) {
                    ans = C;
                }
                if (C -> left) {
                    q.push(C->left);
                    mp[C->left] = C;
                }
                if (C -> right) {
                    q.push(C->right);
                    mp[C->right] = C;
                }
            }
        }
        return ans;
    }
    vector<int> kDist(Node* root, int k) {
        map<Node*, bool> visit;
        visit[root] = 1;
        k++;
        queue<Node*> q({root});
        while (q.size() && k--) {
            int size = q.size();
            vector<int> ans;
            while (size--) {
                Node* C = q.front();
                q.pop();
                ans.push_back(C -> data);
                if (C -> left && !visit.count(C -> left)) {
                    visit[C -> left] = 1;
                    q.push(C -> left);
                }
                if (C -> right && !visit.count(C -> right)) {
                    visit[C -> right] = 1;
                    q.push(C -> right);
                }
                if (mp[C] && !visit.count(mp[C])) {
                    visit[mp[C]] = 1;
                    q.push(mp[C]);
                }
            }
            if (k == 0) {
                sort(begin(ans), end(ans));
                return ans;
            }
        }
        return {};
    }
public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        Node* start = find(root, target);
        return kDist(start, k);
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