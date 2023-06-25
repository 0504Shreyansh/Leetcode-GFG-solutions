class Solution {
public:
    const int mod = 1e9 + 7;
    int count(int start, int finish, int fuel, vector<int>& locations, vector<vector<int>>& dp) {
        int paths = 0;
        if(start == finish) paths++;
        if(dp[start][fuel] != -1) return dp[start][fuel];
        for(int curr = 0; curr < locations.size(); curr++) {
            if(start != curr) {
                if(fuel >= abs(locations[curr] - locations[start])) {
                    paths = (paths + count(curr, finish, fuel - abs(locations[curr] - locations[start]), locations, dp)) % mod;
                }
            }
        }
        return dp[start][fuel] = paths;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>> dp(locations.size(), vector<int> (fuel+1, -1));
        return count(start, finish, fuel, locations, dp);
    }
};