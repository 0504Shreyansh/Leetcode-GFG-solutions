class Solution {
public:
//     void call(int i, int j, int cnt, vector<pair<int,int>> &allPaths, vector<vector<bool>> &vis, int k, int l, vector<vector<int>> grid, int m, int n, int size) {
        
//         if(i==k&&j==l) {
//             cout<<"PAHUNCH : "<<size<<' '<<m*n-cnt<<endl;
//             if(size==m*n-cnt) {
//                 cout<<"ASLI : "<<i<<' '<<j<<endl;
//                 ans++;
//             }
//             return;
//         }
//         vis[i][j] = true;
//         allPaths.push_back({i,j});
//         size++;
//         // cout<<"UP : "<<i<<' '<<j<<endl;
//         if(i-1>=0 && i-1<n && j>=0 && j<m && !vis[i-1][j]) {
//             // vis[i-1][j] = true;
//             // allPaths.push_back({i-1,j});
//             cout<<"UP : "<<i<<' '<<j<<' '<<size<<endl;
//             call(i-1,j,cnt,allPaths,vis,k,l,grid,m,n,size);
//         }
//         if(i+1>=0 && i+1<n && j>=0 && j<m && !vis[i+1][j]) {
//             // vis[i+1][j] = true;
//             // allPaths.push_back({i+1,j});
//             cout<<"DOWN : "<<i<<' '<<j<<' '<<size<<endl;
//             call(i+1,j,cnt,allPaths,vis,k,l,grid,m,n,size);
//         }
//         if(i>=0 && i<n && j-1>=0 && j-1<m && !vis[i][j-1]) {
//             // vis[i][j-1] = true;
//             // allPaths.push_back({i,j-1});
//             cout<<"LEFT : "<<i<<' '<<j<<' '<<size<<endl;
//             call(i,j-1,cnt,allPaths,vis,k,l,grid,m,n,size);
//         }
//         if(i>=0 && i<n && j+1>=0 && j+1<m && !vis[i][j+1]) {
//             // vis[i][j+1] = true;
//             // allPaths.push_back({i,j+1});
//             cout<<"RIGHT : "<<i<<' '<<j<<' '<<size<<endl;
//             call(i,j+1,cnt,allPaths,vis,k,l,grid,m,n,size);
//         }
//         // vis[i][j] = false;
//         // return;
//     }
    int call(vector<vector<int>> grid, int i, int j, int size, int cnt, int n, int m) {
        
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==-1)
            return 0;
        
        if(grid[i][j]==2) {
            if(size+1==cnt)
                return 1;
            return 0;
        }
        
        grid[i][j] = -1;
        int curr = call(grid,i-1,j,size+1,cnt,n,m)+call(grid,i+1,j,size+1,cnt,n,m)+call(grid,i,j-1,size+1,cnt,n,m)+call(grid,i,j+1,size+1,cnt,n,m);
        grid[i][j] = 0;
        
        return curr;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        int kk = -1, ll = -1, cnt = 0, size = 0;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]!=-1) 
                    cnt++;
                
                if(grid[i][j]==1) 
                    kk = i, ll = j;
            }
        }
        
        // call(i,j,cnt,allPaths,vis,k,l,grid,m,n,size);
        return call(grid,kk,ll,size,cnt,n,m);
    }
};