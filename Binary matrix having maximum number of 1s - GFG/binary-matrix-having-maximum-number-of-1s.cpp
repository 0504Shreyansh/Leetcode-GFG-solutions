//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        
        vector<int> ans;
        int rowNum = -1, maxCnt = INT_MIN;
        for(int i = 0; i < N; i++) {
            int ub = upper_bound(mat[i].begin(),mat[i].end(),0)-mat[i].begin();
            int curCnt = N - ub;
            if(maxCnt < curCnt) {
                maxCnt = curCnt;
                rowNum = i;
            }
        }
        
        for(int i = N-1; i >= 0; i--) {
            int ub = upper_bound(mat[i].begin(),mat[i].end(),0)-mat[i].begin();
            int curCnt = N - ub;
            if(curCnt==maxCnt) {
                ans.clear();
                ans.push_back(rowNum);
                ans.push_back(maxCnt);
            }
        }
                
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends