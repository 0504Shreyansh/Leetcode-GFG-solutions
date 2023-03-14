//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minColour(int N, int M, vector<int> mat[]) {
        
        vector<int> adjList[N+1];
        vector<int> inDegree(N+1, 0);
        for(int i = 0; i < M; i++) 
        {
            adjList[mat[i][0]].push_back(mat[i][1]);
            inDegree[mat[i][1]]++;
        }            
        
        queue<int> q;
        for(int i = 0; i < N; i++) 
            if(!inDegree[i])
                q.push(i);
                
        // Just count the levels of topoSortt
        int res = 0;
        while(q.size()) 
        {
            int size = q.size();
            res++;
            while(size--) 
            {
                int curMinion = q.front();
                q.pop();
                for(auto nbrMinion : adjList[curMinion])
                    if(--inDegree[nbrMinion]==0)
                        q.push(nbrMinion);
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M, x, y;
        cin>>N>>M;
        vector<int> mat[M];
        for(int i = 0;i < M;i++){
            cin>>x>>y;
            mat[i].push_back(x);
            mat[i].push_back(y);
        }
        
        Solution ob;
        cout<<ob.minColour(N, M, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends