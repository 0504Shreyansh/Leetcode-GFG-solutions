/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /*
    -1 --> immediately wants a camera
    0 --> no condition
    1 --> can provide with a camera
    */
    int inorder(TreeNode* root, int &camera_count) {
        // no condition for camera for NULL nodes
        if(root == NULL) {
            return 0;
        }
        int left = inorder(root->left, camera_count);
        int right = inorder(root->right, camera_count);
        // if any child immediately wants a camera --> install one.
        if(left == -1 || right == -1) {
            camera_count++;
            return 1;
        }
        // if any child can provide with a camera --> its ok!
        else if(left == 1 || right == 1) {
            return 0;
        }
        // ask parent for cameras
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        int camera_count = 0;
        // if root node wants a camera --> give it one.
        if(inorder(root, camera_count) == -1)
            camera_count++;
        return camera_count;
    }
};