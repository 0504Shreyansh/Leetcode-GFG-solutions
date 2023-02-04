//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
    void dfs(vector<int> graph[], vector<int>&visited, vector<int> &color, int sr, int n, int c) {
        visited[sr] = 1;
        color[sr] = c;
        for(auto nbr: graph[sr]) {
            if(!visited[nbr]) {
                dfs(graph,visited,color,nbr,n,1-c);   
            }
        }
    }
    public:
    int countOfNodes(vector<int> graph[], int n)
    {
        vector<int> color(n+1, -1), visited(n+1);
        for(int i=1;i<=n;i++) {
            if(!visited[i]) {
                dfs(graph,visited,color,i,n,0);
            }
        }
        int e = 0, o = 0;
        for(auto c:color) {
            if(c==1) o++;
            else if(c==0) e++;
        }
        int ans = (o*(o-1))/2 + (e*(e-1))/2;
        return ans;
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
        cin >> n;
        vector<int>graph[n+1];
        for(int i=0;i<n-1;i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        Solution ob;
        cout<<ob.countOfNodes(graph, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends