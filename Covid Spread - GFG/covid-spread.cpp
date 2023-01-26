//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
private:
    int bfs(vector<vector<int>>&grid, vector<vector<int>>&vis) {
        queue<pair<int,int>> q;
        int t = 0, ones = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!vis[i][j] && grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1)
                    ones++;
            }
        }
        
        int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
        
        while(q.size()) {
            int size = q.size();
            for(int k=0;k<size;k++) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                vis[x][y] = 1;
                for(int l=0;l<4;l++) {
                    int nx=x+dx[l], ny=y+dy[l];
                    if(nx>=0&&nx<n&&ny>=0&&ny<m&&!vis[nx][ny]&&grid[nx][ny]==1) {
                        q.push({nx,ny});
                        grid[nx][ny] = 2;
                        ones--;
                    }
                }
            } 
            if(q.size()) t++;
        }
        // cout<<ones<<' '<<t<<endl;
        return (ones==0)?t:-1;
    }
public:
    int helpaterp(vector<vector<int>> hospital)
    {
        int n = hospital.size(), m = hospital[0].size();
        vector<vector<int>> visited(n,vector<int> (m));
        
        return bfs(hospital,visited);
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends