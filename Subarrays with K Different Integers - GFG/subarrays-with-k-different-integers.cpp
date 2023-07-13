//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int f(vector<int>& arr, int N, int k, int maxi) {
        vector<int> mp(maxi + 1);
        int i = 0;
        int ans = 0;
        int count = 0;
        for(int j = 0; j < N; j++) {
            if(++mp[arr[j]] == 1) count++;
            while(count > k) {
                if(--mp[arr[i]] == 0) {
                    count--;
                }
                i++;
            }
            ans += j - i + 1;
        }
        return ans;
    }
    int subarrayCount(vector<int> &arr, int N, int k) {
        int maxi = *max_element(begin(arr),end(arr));
        return f(arr, N, k, maxi) - f(arr, N, k - 1, maxi);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayCount(arr, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends