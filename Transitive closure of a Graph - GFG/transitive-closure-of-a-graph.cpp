//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
private:
    void dfs(int j, int i, vector<vector<int>>& ans, vector<int> G[], vector<int>& visit) {
        ans[j][i] = 1;
        visit[i] = 1;
        for (int &v : G[i]) {
            if (!visit[v]) {
                dfs(j, v, ans, G, visit);
            }
        }
    }
public:
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        vector<int> G[N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i != j && graph[i][j]) {
                    G[i].push_back(j);
                }
            }
        }
        vector<vector<int>> ans(N, vector<int> (N, 0));
        for (int i = 0; i < N; ++i) {
            vector<int> visit(N);
            ans[i][i] = 1;
            dfs(i, i, ans, G, visit);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}
// } Driver Code Ends