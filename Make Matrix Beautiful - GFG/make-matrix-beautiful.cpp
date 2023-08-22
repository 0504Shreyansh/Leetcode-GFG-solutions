//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int N)
    {
        int sum = 0;
        int mRSum = 0, mCSum = 0;
        for (int i = 0; i < N; i++) {
            int cRSum = 0, cCSum = 0;
            for (int j = 0; j < N; j++) {
                sum += matrix[i][j];
                cRSum += matrix[i][j];
                cCSum += matrix[j][i];
            }
            mRSum = max(mRSum, cRSum);
            mCSum = max(mCSum, cCSum);
        }
        return max(mRSum, mCSum) * N - sum;
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
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends