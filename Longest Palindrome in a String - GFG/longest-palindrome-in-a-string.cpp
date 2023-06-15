//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin(string s) {
        int n = s.size();
        int start = -1;
        int len = 0;
        for(int i = 0 ; i < n; i++) {
            int odd_start = i, odd_end = i;
            int oddLength = 1;
            while(odd_start - 1 >= 0 && odd_end + 1 < n && s[odd_start - 1] == s[odd_end + 1]) {
                odd_start--;
                odd_end++;
                oddLength += 2;
            }
            if(len < oddLength) {
                len = oddLength;
                start = odd_start;
            }
            int even_start = i, even_end = i + 1;
            int evenLength = 0;
            while(even_start >= 0 && even_end < n && s[even_start] == s[even_end]) {
                even_start--;
                even_end++;
                evenLength += 2;
            }
            if(len < evenLength) {
                len = evenLength;
                start = even_start + 1;
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