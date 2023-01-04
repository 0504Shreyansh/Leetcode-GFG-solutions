//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        
        sort(intervals.begin(),intervals.end());
        vector<int> ind(n,-1), profit(n,0);
        profit[0] = intervals[0][2];
        int ans = profit[0];
         
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(intervals[j][1]<=intervals[i][0] && profit[i]<=profit[j]+intervals[i][2]) {
                    ind[i] = j;
                    profit[i] = intervals[i][2] + profit[j];
                }        
                else if(intervals[j][1]>intervals[i][0] && profit[i]<=intervals[i][2])
                    profit[i] = intervals[i][2];
            }
            // cout<<i<<' '<<ind[i]<<' '<<profit[i]<<endl;
            ans = max(ans,profit[i]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends