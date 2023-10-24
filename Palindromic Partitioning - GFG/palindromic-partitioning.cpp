//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }
    int solve(int i, int n, string &s, vector<int>& dp) {
        if (i == n) return 0; 
        if (dp[i] != -1) return dp[i];
        string c;
        int ans = 1e3;
        for (int j = i; j < n; j++) {
            c += s[j];
            if (isPalindrome(c)) {
                ans = min(ans, 1 + solve(j + 1, n, s, dp));
            }
        }
        return dp[i] = ans;
    }
    int palindromicPartition(string s) {
        vector<int> dp(s.size(), -1);
        return solve(0, s.size(), s, dp) - 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends