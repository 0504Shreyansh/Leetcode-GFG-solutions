//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    bool isSafe(int row, int col, vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == row || j == col || (col - row) == j - i || (row + col) == (j + i)) && grid[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    vector<vector<int>> ans;
    void solve(int col, int n, vector<int>& t, vector<vector<int>>& grid) {
        if (col == n) {
            ans.push_back(t);
            return ;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, grid)) {
                grid[row][col] = 1;
                t.push_back(row + 1);
                solve(col + 1, n, t, grid);
                t.pop_back();
                grid[row][col] = 0;
            }
        }
    }
public:
    vector<vector<int>> nQueen(int n) {
        vector<int> t;
        vector<vector<int>> grid(n, vector<int> (n));
        solve(0, n, t, grid);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends