class Solution {
public:
        vector<int>dx = {-1,0,+1,0} ; 
        vector<int>dy = {0,-1,0,+1} ; 
    bool isValid(int nr,int nc,int n,int m){
        return nr>=0 && nr<n && nc>=0 && nc<m ;
    }
    int dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis,int gold){
        int n = grid.size() , m=grid[0].size() ,curr=0; 
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nr = row+dx[i] ; 
            int nc = col+dy[i] ; 

            if(isValid(nr,nc,n,m) && !vis[nr][nc] && grid[nr][nc]!=0){
                 //further dfs call 
                 curr=max(curr,dfs(nr,nc,grid,vis,grid[nr][nc]));
             //   cout<<curr<<" ";
            }
        }
      vis[row][col]=0; //backtrack
    return gold+curr;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        //dfs
        int n = grid.size() , m=grid[0].size() ; 
        vector<vector<int>>vis(n,vector<int>(m,0)) ; 
        int maxGold=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //try collecting gold from every point possible
                if(grid[i][j]!=0){
                        //make a dfs call and start collecting gold 
                        int currGold=dfs(i,j,grid,vis,grid[i][j]);
                         maxGold=max(maxGold,currGold);
                }
            }
        }
        return maxGold;
    }
};