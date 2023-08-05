class Solution {
private:
    int count(vector<int>& left, vector<int>& right, int root) {
        return (root == -1) ? 0 : 1 + count(left, right, left[root]) + count(left, right, right[root]);
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // only 1 parent
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                if (++indegree[leftChild[i]] > 1) return false;
            }
            if (rightChild[i] != -1) {
                if (++indegree[rightChild[i]] > 1) return false;
            }
        }
        // only 1 node with no parent
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                if (root == -1) {
                    root = i;
                } else {
                    return false;
                }
            }
        }
        // total nodes must be n
        return count(leftChild, rightChild, root) == n;
    }
};