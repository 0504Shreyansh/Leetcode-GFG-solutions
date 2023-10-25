//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i, int N, int W, int val[], int wt[], vector<vector<int>>& dp) {
        if (i >= N) return 0;
        if (dp[i][W] != -1) return dp[i][W];
        int notPick = solve(i + 1, N, W, val, wt, dp), pick = 0;
        if (W >= wt[i]) pick = val[i] + solve(i, N, W - wt[i], val, wt, dp);
        return dp[i][W] = max(notPick, pick);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N, vector<int> (W + 1, -1));
        return solve(0, N, W, val, wt, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends