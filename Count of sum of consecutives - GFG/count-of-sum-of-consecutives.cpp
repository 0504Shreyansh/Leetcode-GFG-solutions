//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int getCount(int N) {
        int ans = 0;
        int L = 1;
        while ((L * (L + 1)) < 2 * N) {
            double a = 1.0*(N - (L * (L + 1)) / 2) / (1.0*(L + 1));
            if (a == (int)a) {
                ans++;
            }
            L++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.getCount(N) << endl;
    }
    return 0;
}
// } Driver Code Ends