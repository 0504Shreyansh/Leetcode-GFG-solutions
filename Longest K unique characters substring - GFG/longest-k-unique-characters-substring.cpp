//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        vector<int> freq(26);
        int count = 0;
        int i = 0;
        int n = s.size();
        int ans = -1e9;
        for (int j = 0; j < n; j++) {
            if (++freq[s[j] - 'a'] == 1) {
                count++;
            }
            while (count > k) {
                if (--freq[s[i] - 'a'] == 0) {
                    count--;
                }
                i++;
            }
            if (count == k) {
                ans = max(ans, j - i + 1);
            }
        }
        if (ans == -1e9) ans = -1;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends