//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool isPossible(int *arr, int n, int k, long long mid) {
        int cnt = 1;
        int amt = 0;
        for(int i = 0; i < n; i++) {
            if(amt + arr[i] <= mid) {
                amt += arr[i];
            } else {
                cnt++;
                if(cnt > k) return 0;
                if(arr[i] > mid) return 0;
                amt = arr[i];
            }
        }
        return 1;
    }
    long long minTime(int arr[], int n, int k)
    {
        
        int low = arr[0];
        long long high = 0;
        for(int i = 0; i < n; i++) {
            high += arr[i];
        }
        long long ans = -1;
        while(low <= high) {
            long long mid = (low + high) / 2;
            if(isPossible(arr, n, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans==-1 ? INT_MAX : ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends