//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    bool allStars(string &s, int j) {
        for(int i = 0; i <= j; i++)
            if(s[i] != '*')
                return false;
        return true;
    }
    int solve1(int i, int j, string &s, string &t, vector<vector<int>>& dp) {
    
        if(i<0 && j<0) return true;
        if(i<0) return allStars(t, j);
        if(j<0) return false;
    
        if(dp[i][j] != -1) return dp[i][j];
    
        if(s[i] == t[j]) return dp[i][j] = solve1(i-1, j-1, s, t, dp);
        if(t[j] == '?') return dp[i][j] = solve1(i-1, j-1, s, t, dp);
        if(t[j] == '*') return dp[i][j] = solve1(i-1, j, s, t, dp) or solve1(i, j-1, s, t, dp);
        return dp[i][j] = false;
    }
    int wildCard(string t, string s)
    {
        vector<vector<int>> dp(s.size()+1, vector<int> (t.size()+1, -1));
        return solve1(s.size()-1, t.size()-1, s, t, dp);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends