class Solution {
private:
    int dfs(int root, vector<int>& leftChild, vector<int>& rightChild) {
        return (root == -1) ? 0 : 1 + dfs(leftChild[root], leftChild, rightChild) + dfs(rightChild[root], leftChild, rightChild); 
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        /* 3 conditions -->
          1. one node with indegree[node] = 0 (parent)
          2. no node can have indegree[node] > 1
          3. all nodes in one component
        */
        vector<int> indegree(n), outdegree(n);
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) {
                if (++indegree[leftChild[i]] > 1) 
                    return false;
                outdegree[i]++;
            }
            if (rightChild[i] != -1) {
                if (++indegree[rightChild[i]] > 1) 
                    return false;
                outdegree[i]++;
            }
        }
        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                if (root == -1) {
                    root = i;
                } else {
                    return false;
                }
            }
        }
        if (root == -1) {
            return false;
        }
        return (dfs(root, leftChild, rightChild) == n);
    }
};