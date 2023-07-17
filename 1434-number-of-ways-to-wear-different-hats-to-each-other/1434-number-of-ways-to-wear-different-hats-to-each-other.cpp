class Solution {
public:
    int solve(int i, int mask, vector<vector<int>>& persons, int allMask, vector<vector<int>>& dp) {
        if(mask == allMask) {
            return 1;
        }
        if(i >= persons.size()) {
            return 0;
        }
        if(dp[i][mask] != -1) {
            return dp[i][mask];
        }
        int notPick = solve(i + 1, mask, persons, allMask, dp), pick = 0;
        for(int j = 0; j < persons[i].size(); ++j) {
            if(!(mask & (1 << persons[i][j]))) {
                notPick += solve(i + 1, mask | (1 << persons[i][j]), persons, allMask, dp);
                notPick %= 1000000007;
            }
        }
        return dp[i][mask] = (pick + notPick) % 1000000007;
    }
    int numberWays(vector<vector<int>>& hats) {
        map<int, vector<int>> mp;
        for(int i = 0; i < hats.size(); i++) {
            for(auto &it : hats[i]) {
                mp[it].push_back(i);
            }
        }
        vector<vector<int>> nums;
        for(auto &it : mp) 
            nums.push_back(it.second);
        
        vector<vector<int>> dp(41, vector<int> (1 << hats.size(), -1));
        return solve(0, 0, nums, (1 << hats.size()) - 1, dp);
    }
};