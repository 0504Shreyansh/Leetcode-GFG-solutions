//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool isPossible(int arr[], int N, int k, int mid) {
        int cnt = 1;
        int load = 0;
        for (int i = 0; i < N; i++) {
            if(load + arr[i] <= mid) {
                load += arr[i];
            } else {
                load = arr[i];
                cnt++;
                if(cnt > k || arr[i] > mid) return 0;
            }
        }
        return 1;
    }
    int leastWeightCapacity(int arr[], int N, int k) {
        int low = 0;
        int high = 0;
        for (int i = 0; i < N; i++) {
            high += arr[i];
        }
        int ans = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(isPossible(arr, N, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
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
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends