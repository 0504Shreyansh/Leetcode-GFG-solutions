#define mod 1000000007
class Solution {
public:
    int solve(int n, char prev, vector<vector<int>>& dp) {
        if(n == 0) {
            return 1;
        }
        
        if(dp[n][prev - 'a'] != -1) {
            return dp[n][prev - 'a'];
        }
        
        if(prev == 'z') {
            int prevA = solve(n - 1, 'a', dp);
            int prevE = solve(n - 1, 'e', dp);
            int prevI = solve(n - 1, 'i', dp);
            int prevO = solve(n - 1, 'o', dp);
            int prevU = solve(n - 1, 'u', dp);
            return ((((((prevA + prevE) % mod) + prevI) % mod + prevO) % mod + prevU) % mod) % mod;
        }
        
        int cur = 0;
        if(prev == 'a') {
            int prevE = solve(n - 1, 'e', dp); 
            cur = (cur + prevE) % mod;
            return dp[n][prev - 'a'] = cur % mod;
        }
        
        else if(prev == 'e') {
            int prevA = solve(n - 1, 'a', dp);
            int prevI = solve(n - 1, 'i', dp);
            cur = (cur + prevA + prevI) % mod;
            return dp[n][prev - 'a'] = cur % mod;
        }
        
        else if(prev == 'i') {
            int prevA = solve(n - 1, 'a', dp);
            int prevE = solve(n - 1, 'e', dp);
            int prevO = solve(n - 1, 'o', dp);
            int prevU = solve(n - 1, 'u', dp); 
            cur = (cur + ((((prevA + prevE) % mod) + prevO) % mod + prevU) % mod) % mod;
            return dp[n][prev - 'a'] = cur % mod;
        }
        
        else if(prev == 'o') {
            int prevI = solve(n - 1, 'i', dp);
            int prevU = solve(n - 1, 'u', dp); 
            cur = (cur + prevI + prevU) % mod;
            return dp[n][prev - 'a'] = cur % mod;
        }
        
        else {
            int prevA = solve(n - 1, 'a', dp);
            cur = (cur + prevA) % mod;
            return dp[n][prev - 'a'] = cur % mod;
        }         
    }
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n + 1, vector<int> (26, -1));
        return solve(n, 'z', dp);
    }
};