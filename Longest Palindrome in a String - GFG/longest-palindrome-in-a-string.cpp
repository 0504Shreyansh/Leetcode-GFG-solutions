//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        int start = 0, len = 1;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int l = i, h = i;
            while (l >= 0 && h < n && s[l] == s[h]) l--, h++;
            if (h - l - 1 > len) {
                start = l + 1;
                len = h - l - 1;
            }
            l = i, h = i + 1;
            while (l >= 0 && h < n && s[l] == s[h]) l--, h++;
            if (h - l - 1 > len) {
                start = l + 1;
                len = h - l - 1;
            }
        }
        return s.substr(start, len);
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