//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    #define mod 1000000007
    int solve(int n, int x, int i, vector<vector<int>>& dp) {
        if(n < pow(i, x)) {
            return 0;
        }
        if(n == pow(i, x)) {
            return 1;
        }
        if(dp[n][i] != -1) {
            return dp[n][i];
        }
        int notPick = solve(n, x, i + 1, dp);
        int pick = solve(n - pow(i, x), x, i + 1, dp);
        return dp[n][i] = (pick + notPick) % mod;
    }
    int numOfWays(int n, int x)
    {
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        // return solve(n, x, 1, dp);
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends