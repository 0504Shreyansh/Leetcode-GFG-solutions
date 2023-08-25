//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool solve(int i, int j, string &A, string &B, string &C, vector<vector<int>>& dp) {
        if (i == 0) return (B.substr(0, j) == C.substr(0, j));
        if (j == 0) return (A.substr(0, i) == C.substr(0, i));
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        bool ans = false;
        if (A[i - 1] == C[i + j - 1]) {
            ans |= solve(i - 1, j, A, B, C, dp);
        }
        if (B[j - 1] == C[i + j - 1]) {
            ans |= solve(i, j - 1, A, B, C, dp);
        }
        return dp[i][j] = ans;
    }
    bool isInterleave(string A, string B, string C) 
    {
        int n = A.size(), m = B.size(), k = C.size();
        if (n + m != k) return false;
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        return solve(n, m, A, B, C, dp);
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends