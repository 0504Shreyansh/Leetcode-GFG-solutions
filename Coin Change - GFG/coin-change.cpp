//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {
        vector<long long> dp(sum+1, 0), prev(sum+1, 0);
        prev[0] = 1;
        for (int i = N-1; i >= 0; i--) {
            for (int j = 0; j <= sum; j++) {
                long long notPick = prev[j];
                long long pick = 0;
                if (j >= coins[i]) pick = dp[j - coins[i]];
                dp[j] = pick + notPick;
            }
            prev = dp;
        }
        return dp[sum];
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