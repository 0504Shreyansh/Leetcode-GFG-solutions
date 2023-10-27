//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int solve(int i, int j, string &s, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == s[j]) 
            return dp[i][j] = solve(i + 1, j - 1, s, dp);
        return dp[i][j] = 1 + min(solve(i + 1, j, s, dp), solve(i, j - 1, s, dp));
    }
    int minimumNumberOfDeletions(string S) { 
        int n = S.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(0, n - 1, S, dp);
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends