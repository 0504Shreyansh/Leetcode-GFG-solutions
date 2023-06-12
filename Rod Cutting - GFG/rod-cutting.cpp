//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int dp[1001][1001];
    int solve(int i, int* price, int n, int nn) {
        if(n == 0 || i >= nn) return 0;
        if(dp[i][n] != -1) return dp[i][n];
        int cutHere = 0, noCut = solve(i + 1, price, n, nn);
        if(n >= i + 1) 
            cutHere = price[i] + solve(i, price, n - (i + 1), nn);
        return dp[i][n] = max(noCut, cutHere);
    }
    int cutRod(int price[], int n) {
        memset(dp, -1, sizeof(dp));
        return solve(0, price, n, n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends