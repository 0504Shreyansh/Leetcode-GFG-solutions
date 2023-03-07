class Solution {
public:
    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
    map<int,int> areaSize;
    int dfs(int i, int j, vector<vector<int>>& grid, int color) {
        if(i<0 || i>=grid.size() || j<0 || j>=grid.size() || grid[i][j]!=1)
            return 0;
        // cout<<i<<' '<<j<<endl;
        grid[i][j] = color;
        int area = 0;
        for(auto k : dir)
            area += dfs(i+k.first, j+k.second, grid, color);
        return area+1;
    }
    int largestIsland(vector<vector<int>>& grid) {
        
        int n = grid.size(), color = 2;
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int curArea = dfs(i, j, grid, color);
                    areaSize[color] = (curArea);
                    color++;
                }
            }
        }
        
//         for(auto i: grid) {
//             for(auto j : i) cout<<j<<" "; cout<<endl;
//         }
        
//         for(auto i: areaSize) cout<<i.first<<' '<<i.second<<endl;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int cnt = 0;
                if(!grid[i][j]) {
                    int curArea = 0;
                    unordered_set<int> clrs;
                    // cout<<i<<' '<<j<<"->\n";
                    for(auto k : dir) {
                        int newX = i + k.first, newY = j + k.second;
                        if(newX>=0 && newX<n && newY>=0 & newY<n && grid[newX][newY]!=0 && clrs.count(grid[newX][newY])==0) {
                            clrs.insert(grid[newX][newY]);
                            curArea += areaSize[grid[newX][newY]];
                            // cout<<newX<<' '<<newY<<' '<<curArea<<endl;
                        }
                    }
                    cnt = max(cnt, curArea+1);
                }
                ans = max(ans, cnt);
            }
        }
        
        
        return (ans==0) ? n*n : ans;
    }
};