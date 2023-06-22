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
        return (root == NULL) ? "#" :
            to_string(root->val) + "#" + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* createTree(stringstream& ss) {
        string s;
        getline(ss, s, '#');
        if(s.size() == 0) return NULL;
        TreeNode* root = new TreeNode(stoi(s));
        root->left = createTree(ss);
        root->right = createTree(ss);
        return root;
    }
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return createTree(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;