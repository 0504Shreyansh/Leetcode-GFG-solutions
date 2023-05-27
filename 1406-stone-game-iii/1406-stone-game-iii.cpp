class Solution {
public:
    int solve(int i, bool aliceTurn, bool bobTurn, vector<int>& stoneValue, vector<vector<vector<int>>>& dp) {
        int n = stoneValue.size();
        if(i >= n) {
            return 0;
        }
        if(dp[i][aliceTurn][bobTurn] != -1) {
            return dp[i][aliceTurn][bobTurn];
        }
        int ans;
        if(aliceTurn) {
            ans = -2e9;
            int take1 = -2e9, take2 = -2e9, take3 = -2e9;
            take1 = stoneValue[i] + solve(i + 1, false, true, stoneValue, dp);
            if(i + 1 < n) take2 = stoneValue[i] + stoneValue[i + 1] + solve(i + 2, false, true, stoneValue, dp);
            if(i + 2 < n) take3 = stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] +
                                solve(i + 3, false, true, stoneValue, dp);
            ans = max({ans, take1, take2, take3});
        }
        else {
            ans = 2e9;
            int skip1 = solve(i + 1, true, false, stoneValue, dp);
            int skip2 = solve(i + 2, true, false, stoneValue, dp);
            int skip3 = solve(i + 3, true, false, stoneValue, dp);
            ans = min({ans, skip1, skip2, skip3});
        }
        return dp[i][aliceTurn][bobTurn] = ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int totalScore = 0;
        int n = stoneValue.size();
        for(auto it : stoneValue)
            totalScore += it;
        vector<vector<vector<int>>> dp(n, 
                    vector<vector<int>> (2, vector<int> (2, -1)));
        int aliceScore = solve(0, true, false, stoneValue, dp);
        
        return (totalScore - aliceScore < aliceScore) ? "Alice" : 
            ((totalScore - aliceScore > aliceScore) ? "Bob" : "Tie");
    }
};