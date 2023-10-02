//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	     int mod=1e9+7;
        int n=s.size();
        unordered_map<char,int>m;
        vector<int>dp(n+1);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            dp[i]= (2*dp[i-1])%mod;
            char ch=s[i-1];
            if(m[ch]){
                int j=m[ch];
                dp[i]=(dp[i]-dp[j-1]+mod)%mod;
            }
            m[ch]=i;
        }
        return dp[n];
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends