//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    const int mod = 1e9 + 7;
    int countWays(int n)
    {
        vector<int> f(n + 2, 0);
        f[1] = 1;
        for(int i = 2; i <= n+1; i++) {
            f[i] = (f[i - 1] + f[i - 2]) % mod;
        }
        return f[n+1];
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends