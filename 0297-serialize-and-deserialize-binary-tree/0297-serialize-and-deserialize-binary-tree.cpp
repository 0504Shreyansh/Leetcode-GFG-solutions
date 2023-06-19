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
        queue<TreeNode*> Q({root});
        string ans;
        while(Q.size()) {
            int size = Q.size();
            while(size--) {
                TreeNode *curr = Q.front();
                Q.pop();
                if(curr) {
                    ans += to_string(curr -> val) + ",";
                } else {
                    ans += ("#,");
                    continue;
                }
                if(curr->left) {
                    Q.push(curr -> left);
                } else {
                    Q.push(NULL);
                }
                if(curr -> right) {
                    Q.push(curr -> right); 
                } else {
                    Q.push(NULL);
                }
            }
        }
        ans.pop_back();
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data[0] == '#') {
            return NULL;
        }
       
        stringstream ss(data);
        string word;
        vector<string> nodes;
        while(std::getline(ss, word, ',')) {
            nodes.push_back(word);
        }
        
        int i = 1;
        TreeNode *root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> Q({root});
        while(Q.size()) {
            int size = Q.size();
            while(size--) {
                TreeNode *curr = Q.front();
                Q.pop();
                if(nodes[i] != "#") {
                    curr -> left = new TreeNode(stoi(nodes[i]));
                    Q.push(curr -> left);
                } 
                i++;
                if(nodes[i] != "#") {
                    curr -> right = new TreeNode(stoi(nodes[i]));
                    Q.push(curr -> right);
                }
                i++;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));