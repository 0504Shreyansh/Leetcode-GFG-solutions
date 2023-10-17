class Solution {
private:
    bool dfs(int u, vector<int>& leftChild, vector<int>& rightChild, vector<int>& visit) {
        visit[u] = 1;
        int ans = false;
        if (leftChild[u] != -1) {
            if (visit[leftChild[u]]) return true;
            ans |= dfs(leftChild[u], leftChild, rightChild, visit);
        }
        if (rightChild[u] != -1) {
            if (visit[rightChild[u]]) return true;
            ans |= dfs(rightChild[u], leftChild, rightChild, visit);
        }
        return ans;
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        // each child has only one 1 parent
        vector<int> in(n);
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                if (++in[leftChild[i]] > 1) return false;
            }
            if (rightChild[i] != -1) {
                if (++in[rightChild[i]] > 1) return false;
            }   
        }
        
        // only one root
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
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
        
        // no cycle
        vector<int> visit(n, 0);
        bool isCycle = dfs(root, leftChild, rightChild, visit);
        if (isCycle) return false;
        for (int i = 0; i < n; i++) {
            if (!visit[i]) return false;
        }
        return true;
    }
};