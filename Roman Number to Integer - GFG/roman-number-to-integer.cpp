//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int contribution(char t) {
        if (t == 'I') return 1;
        if (t == 'V') return 5;
        if (t == 'X') return 10;
        if (t == 'L') return 50;
        if (t == 'C') return 100;
        if (t == 'D') return 500;
        return 1000;
    }
    
    bool matching(char c, char t) {
        vector<char> romans = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        for (int i = 0; i < romans.size(); i++) {
            if (romans[i] == t) {
                for (int j = 0; j < i; j++) {
                    if (romans[j] == c) return true;
                }
            }
        }
        return false;
    }
    int romanToDecimal(string &s) {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && matching(s[i], s[i + 1])) {
                ans += contribution(s[i + 1]) - contribution(s[i]);
                i++;
            } else {
                ans += contribution(s[i]);
            }
        }
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
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends