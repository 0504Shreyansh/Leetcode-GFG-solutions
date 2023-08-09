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
        if (root == nullptr) return "#";
        string res = to_string(root->val);
        string l = serialize(root -> left);
        string r = serialize(root -> right);
        return (res + "," + l + "," + r);
    }

    // Decodes your encoded data to tree.
    TreeNode* build(vector<string>& nodes, int& i) {
        if (nodes[i] == "#") {
            i++;
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(nodes[i++]));
        root -> left = build(nodes, i);
        root -> right = build(nodes, i);
        return root;
    }
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string word;
        vector<string> nodes;
        while (std::getline(ss, word, ',')) {
            nodes.push_back(word);
        }
        int i = 0;
        return build(nodes, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));