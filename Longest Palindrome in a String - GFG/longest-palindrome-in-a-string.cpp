//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string check1(string s, int i) {
        int x = i, y = i;
        while(x-1>=0 && y+1<s.size() && s[x-1]==s[y+1]) {
            x--, y++;
        }
        return s.substr(x, y-x+1);
    }
    string check2(string s, int i) {
        int x = i, y = i+1;
        if(y<s.size() && s[x] != s[y]) return s.substr(x, 1);
        while(x-1>=0 && y+1<s.size() && s[x-1]==s[y+1]) {
            x--, y++;
        }
        return s.substr(x, y-x+1);
    }
    string longestPalin (string S) {
        
        int n = S.size();
        string ans = "";
        for(int i = 0; i < n; i++) {
            string oddLength = check1(S, i);
            string evenLength = check2(S, i);
            if(ans.size()==0) {
                if(oddLength.size() > evenLength.size()) ans = oddLength;
                else ans = evenLength;
            } 
            if(oddLength.size() > evenLength.size()) 
                if(ans.size() < oddLength.size())
                    ans = oddLength;
            if(oddLength.size() < evenLength.size()) 
                if(ans.size() < evenLength.size())
                    ans = evenLength;
            // cout<<oddLength<<' '<<evenLength<<' '<<ans<<endl;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends