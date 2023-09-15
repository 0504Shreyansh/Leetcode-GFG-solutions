//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    bool check(int i, int n, int sum, int arr[], vector<vector<int>>& dp) {
        if (i >= n) return (sum == 0);
        if (dp[i][sum] != -1) return dp[i][sum];
        bool ans = check(i + 1, n, sum, arr, dp);
        if (sum >= arr[i]) ans |= check(i + 1, n, sum - arr[i], arr, dp);
        return dp[i][sum] = ans;
    }
public:
    int equalPartition(int n, int arr[])
    {
        int sum = accumulate(arr, arr + n, 0);
       if (sum & 1) return false;
       vector<vector<int>> dp(n, vector<int> (sum + 1, -1));
       return check(0, n, sum / 2, arr, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends