//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    long long solve(int i, int coins[], int N, int sum) {
        if (i >= N) return (sum == 0);
        long long notPick = solve(i + 1, coins, N, sum);
        long long pick = 0;
        if (sum >= coins[i]) pick = solve(i, coins, N, sum - coins[i]);
        return pick + notPick;
    }
  public:
    long long int count(int coins[], int N, int sum) {
        vector<vector<long long>> dp(N+1, vector<long long> (sum+1, 0));
        
        dp[N][0] = 1;
        for (int i = N-1; i >= 0; i--) {
            for (int j = 0; j <= sum; j++) {
                long long notPick = dp[i + 1][j];
                long long pick = 0;
                if (j >= coins[i]) pick = dp[i][j - coins[i]];
                dp[i][j] = pick + notPick;
            }
        }
        return dp[0][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends