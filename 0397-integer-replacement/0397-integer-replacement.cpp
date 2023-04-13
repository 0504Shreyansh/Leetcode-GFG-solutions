class Solution {
public:
    // INT_MAX -> \U0001f622
    unordered_map<int,int> dp;
    long solve(long n) {
        if(n==1) {
            return 0;
        }
        
        if(dp.find(n) != dp.end()) {
            return dp[n];
        }
        
        return (n%2==0) ? dp[n] = 1 + solve(n/2) 
               : dp[n] = 1 + min(solve(n-1), solve(n+1));
    }
    int integerReplacement(int n) {
        return solve(n);       
    }
};

