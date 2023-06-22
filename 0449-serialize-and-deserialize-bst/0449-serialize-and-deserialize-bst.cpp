/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) {
            return "#";
        }
        string ans = to_string(root->val) + ',';
        queue<TreeNode*> q({root});
        while(q.size()) {
            int size = q.size();
            while(size--) {
                TreeNode* curr = q.front();
                q.pop();
                if(!curr) continue;
                if(curr->left) {
                    q.push(curr->left);
                    ans += to_string(curr->left->val) + ',';
                } else {
                    q.push(NULL);
                    ans += "#,";
                }
                if(curr->right) {
                    q.push(curr->right);
                    ans += to_string(curr->right->val) + ',';
                } else {
                    q.push(NULL);
                    ans += "#,";
                }
            }
        }
        ans.pop_back();
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // cout << data << endl;
        if(data[0] == '#') {
            return NULL;
        }
        vector<string> nodes;
        stringstream ss(data);
        string word;
        while(std::getline(ss, word, ','))
            nodes.push_back(word);
        TreeNode *root = new TreeNode(stoi(nodes[0]));
        int i = 1;
        queue<TreeNode*> q({root});
        while(q.size()) {
            int size = q.size();
            while(size--) {
                TreeNode *curr = q.front();
                q.pop();
                if(nodes[i] != "#") {
                    curr -> left = new TreeNode(stoi(nodes[i]));
                    q.push(curr->left);
                }
                i++;
                if(nodes[i] != "#") {
                    curr -> right = new TreeNode(stoi(nodes[i]));
                    q.push(curr->right);
                } 
                i++;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;