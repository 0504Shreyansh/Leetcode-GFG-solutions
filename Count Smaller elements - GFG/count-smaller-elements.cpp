//{ Driver Code Starts
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// } Driver Code Ends
//User function template for C++

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = 
tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

class Solution{
public:	
	vector<int> constructLowerArray(int *arr, int n) {
	    vector<int> res(n);
	    ordered_set<int> OS;
	    for(int i = n - 1; i >= 0; i--) {
	        res[i] = OS.order_of_key(arr[i]);
	        OS.insert(arr[i]);
	    }
	    return res;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.constructLowerArray(arr, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends