//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isPossible(int mid, int arr[], int K, int n) {
        int cnt = 1;
        int amount = 0;
        for(int i = 0; i < n; i++) {
            if(amount + arr[i] <= mid) {
                amount += arr[i];
            } else {
                cnt++;
                if(cnt > K) return false;
                if(arr[i] > mid) return false;
                amount = arr[i];
            }
        }
        return true;
    }
    int splitArray(int arr[] ,int N, int K) {
        int sum = 0;
        for(int i = 0; i < N; i++) {
            sum += arr[i];
        }
        int low = 0;
        int high = sum;
        int res = sum;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(isPossible(mid, arr, K, N)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends