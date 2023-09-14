//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
private:
    const int mod = 1e9 + 7;
    int solve(int i, int n, int sum, int arr[], vector<vector<int>>& dp) {
       if (i >= n) return (sum == 0);
       if (dp[i][sum] != -1) return dp[i][sum];
       int ans = solve(i + 1, n, sum, arr, dp);
       if (sum >= arr[i]) ans += solve(i + 1, n, sum - arr[i], arr, dp);
       return dp[i][sum] = ans % mod;
    }

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<int>> dp(n, vector<int> (sum + 1, -1));
        return solve(0, n, sum, arr, dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends