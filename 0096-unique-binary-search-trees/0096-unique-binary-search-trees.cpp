class Solution {
public:
    int numTrees(int n) {
        /*Nth catalan number -> no. of valid paranthesis, no. of unique BST
        1, 2, 5, 14 ...
        */
        
        vector<int> dp(n+1);
        dp[0]=dp[1]=1;
        for(int i = 2; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                dp[i] = dp[i] + dp[j]*dp[i-1-j];
            }
        }
        return dp[n];
        
        /*Take every unique node -> 
        1. 0 nodes on the left and n-1 nodes on the right
        2. 1 node on the left and n-2 nodes on the right ...
        (n-1). n-1 nodes on the left and 0 node on the right.
        => c(0)*c(n-1) + c(1)*c(n-2) + ... + c(n-1)*c(0)
        => SUM(c(j)*c(n-1-j)) for all j belongs to [0, i-1]
        */
        
    }
};