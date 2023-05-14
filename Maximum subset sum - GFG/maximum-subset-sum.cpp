//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
    // long long solveIt(int i, vector<int>& A, bool prevSelected, vector<vector<int>>& dp) {
    //     if(i == A.size()) {
    //         return 0;
    //     }
    
    //     if(dp[i][prevSelected] != -1) {
    //         return dp[i][prevSelected];
    //     }
    
    //     if(prevSelected == false) {
    //         return dp[i][prevSelected] = max(solveIt(i + 1, A, true, dp), A[i] + solveIt(i + 1, A, false, dp));
    //     }
    
    //     return dp[i][prevSelected] = (A[i] + solveIt(i + 1, A, false, dp));
    // }
    long long findMaxSubsetSum(int N, vector<int> &A) {
        int next[2] = {0};
        int prev[2];
        for(int i = N - 1; i >= 0; i--) {
            prev[0] = max(next[1], A[i] + next[0]);
            prev[1] = A[i] + next[0];
            next[0] = prev[0];
            next[1] = prev[1];
        }
        
        return prev[0];
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends