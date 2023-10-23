//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    int ans = 0;
	    vector<int> sum(n);
	    for (int i = 0; i < n; ++i) {
	        sum[i] = arr[i];
	        ans = max(ans, sum[i]);
	        for (int j = 0; j < i; j++) {
	            if (arr[j] < arr[i]) {
	                sum[i] = max(sum[i], arr[i] + sum[j]);
	                ans = max(ans, sum[i]);
	            }
	        }
	    } 
	    return ans;
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
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends