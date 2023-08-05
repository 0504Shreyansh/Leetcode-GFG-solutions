class Solution {
private:
    int count(vector<int>& left, vector<int>& right, int root) {
        return (root == -1) ? 0 : 1 + count(left, right, left[root]) + count(left, right, right[root]);
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                if (++indegree[leftChild[i]] > 1) return false;
            }
            if (rightChild[i] != -1) {
                if (++indegree[rightChild[i]] > 1) return false;
            }
        }
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
        return count(leftChild, rightChild, root) == n;
    }
};