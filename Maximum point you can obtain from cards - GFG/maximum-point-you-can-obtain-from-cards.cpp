//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxScore(vector<int> &nums, int n, int k) {
        int i = 0;
        long long sum = 0;
        long long ans = 0;
        long long s = accumulate(begin(nums),end(nums),0);
        if(k == n) return s;
        for(int j = 0; j < n; j++) { 
            s -= nums[j];
            if(j - i + 1 == n - k) {
                ans = max(ans, s);
                s += nums[i];
                i++;
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
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends