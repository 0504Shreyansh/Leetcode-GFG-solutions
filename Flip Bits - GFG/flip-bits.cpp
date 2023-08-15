//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int A[], int n)
    {
        int cnt0 = 0, cnt1 = 0;
        int i = 0;
        int diff = 0;
        int l = -1, r = -1;
        for (int j = 0; j < n; j++) {
            if (A[j] == 1) cnt1++;
            else cnt0++;
            while (cnt1 > cnt0) {
                if (A[i] == 1) cnt1--;
                else cnt0--;
                i++;
            }
            if (cnt0 - cnt1 > diff) {
                r = j, l = i;
                diff = cnt0 - cnt1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (l <= i && i <= r) {
                if (A[i] == 0) ans++;
            } else {
                if (A[i] == 1) ans++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends