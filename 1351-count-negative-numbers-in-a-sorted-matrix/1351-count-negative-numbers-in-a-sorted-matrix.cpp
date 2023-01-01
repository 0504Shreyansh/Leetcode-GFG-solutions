class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++) {
            reverse(grid[i].begin(),grid[i].end());
            // int l=0, h=m-1;
            // while(l<=h) {
            //     int m=(l+h)/2;
            //     if(grid[i][m]>=0) l=m+1;
            //     else h=m-1;
            // }
            // cout<<m<<endl;
            int x = upper_bound(grid[i].begin(),grid[i].end(),-1) - grid[i].begin();
            ans += x;
        }
        
        return ans;
    }
};