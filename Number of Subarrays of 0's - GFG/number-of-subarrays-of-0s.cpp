//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

long long int no_of_subarrays(int n, vector<int> &nums) {
    int i = 0;
    int j = 0;
    long long int res = 0;
    while(i<n && j<n) {
        i = j;
        while(j+1<n && nums[j+1]==0 && nums[i]==0)
            j++;
        long long int len = (nums[i]==0) ? j-i+1 : 0;
        res += (len*(len+1)) / 2;
        j++;
    }
    return res;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << no_of_subarrays(n, arr) << endl;
    }
}

// } Driver Code Ends