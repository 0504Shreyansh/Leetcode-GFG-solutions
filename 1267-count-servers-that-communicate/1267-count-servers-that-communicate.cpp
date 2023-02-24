class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        set<pair<int,int>> st;
        
        //Insert from each rows if there are more than 1 comps
        for(int row = 0; row < n; row++) {
            int cnt = 0;
            for(int col = 0; col < m; col++) 
                cnt += (grid[row][col]);
            if(cnt>1) {
                for(int col = 0; col < m; col++) {
                    if(grid[row][col])
                        st.insert({row, col});
                }
            }
        }
        
        //Insert from each cols if there are more than 1 comps
        for(int col = 0; col < m; col++) {
            int cnt = 0;
            for(int row = 0; row < n; row++) 
                cnt += grid[row][col];
            if(cnt>1) {
                for(int row = 0; row < n; row++) {
                    if(grid[row][col])
                        st.insert({row, col});
                }
            }
        }
        
        return st.size();
    }
};