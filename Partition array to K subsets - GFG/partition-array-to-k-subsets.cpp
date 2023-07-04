//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    bool solve(int i, int mask, int *a, int n, int k, int currSum, int getSum) {
        if(k == 0) return true;
        if(currSum == getSum) {
            return solve(0, mask, a, n, k - 1, 0, getSum);
        }
        for(int j = i; j < n; ++j) {
            if(mask & (1 << j)) continue;
            if(a[j] + currSum <= getSum) {
                if(solve(j + 1, mask | (1 << j), a, n, k, currSum + a[j], getSum)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += a[i];
        }
        if(sum % k != 0) {
            return false;
        }
        return solve(0, 0, a, n, k, 0, sum / k);                  
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends