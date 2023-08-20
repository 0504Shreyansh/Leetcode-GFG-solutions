//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isProduct(int arr[], int n, long long x) {
        map<long long, int> m;
        for (int i = 0; i < n; ++i) {
            if (arr[i] == 0 && x == 0) {
                return 1;
            }
            else if (arr[i] != 0 && x % arr[i] == 0 && m[x / arr[i]]) {
                return 1;
            }
            m[arr[i]]++;
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        long long x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.isProduct(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}
// } Driver Code Ends