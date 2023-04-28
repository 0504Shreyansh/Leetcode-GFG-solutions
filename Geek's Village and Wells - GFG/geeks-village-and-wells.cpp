//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<pair<int,int>> direction = {{-1,0},{1,0},{0,1},{0,-1}};
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        
        vector<vector<int>> minTime(n, vector<int> (m, 0));
        vector<vector<int>> vis(n, vector<int> (m, 0));
        queue<pair<int,int>> Q;
        
        // Push all the wells coordinate in the queue to perform bfs
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(c[i][j]=='W') {
                    Q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        
        // Set a timer 
        int timer = 0;
        while(!Q.empty()) {
            int size = Q.size();
            timer += 2;
            while(size--) {
                auto coor = Q.front();
                Q.pop();
                int x = coor.first, y = coor.second;
                for(auto k : direction) {
                    int X = x + k.first, Y = y + k.second;
                    if(X>=0 && X<n && Y>=0 && Y<m && !vis[X][Y] && (c[X][Y]=='H' || c[X][Y]=='.')) {
                        vis[X][Y] = 1;
                        Q.push({X, Y});
                        if(c[X][Y]=='.')
                            minTime[X][Y] = 0;
                        else 
                            minTime[X][Y] = timer;
                    }
                }
            }
        }
        
        // Check for unreachable N's and H's
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j]) {
                    if(c[i][j]=='H') {
                        minTime[i][j] = -1;
                    }
                    else {
                        minTime[i][j] = 0;
                    }
                }
            }
        }
        
        return minTime;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends