//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(int low, int mid, int high, long long A[]) {
        long long cnt = 0;
        vector<long long> temp(high - low + 1);
        int i = low, j = mid + 1, k = 0;
        while (i <= mid && j <= high) {
            if (A[i] <= A[j]) {
                temp[k++] = A[i++];
            } else {
                cnt += (mid - i + 1);
                temp[k++] = A[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = A[i++];
        }
        while (j <= high) {
            temp[k++] = A[j++];
        }
        for (int i = low; i <= high; i++) {
            A[i] = temp[i - low];
        }
        return cnt;
    }
    
    long long mergeSort(int low, int high, long long A[]) {
        if (low == high) return 0;
        int mid = (low + high) / 2;
        long long ans = 0;
        ans += mergeSort(low, mid, A);
        ans += mergeSort(mid + 1, high, A);
        ans += merge(low, mid, high, A);
        return ans;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        return mergeSort(0, N - 1, arr);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends