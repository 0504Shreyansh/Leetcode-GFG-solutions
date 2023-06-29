class Solution {
public:
    int solve(int i, int j, bool turn, vector<int>& A, vector<vector<vector<int>>>& dp) {
        if(i > j) return 0;
        if(dp[i][j][turn] != -1) return dp[i][j][turn];
        if(turn) return dp[i][j][turn] = max(A[i] + solve(i + 1, j, !turn, A, dp), A[j] + solve(i, j - 1, !turn, A, dp));
        return dp[i][j][turn] = min(solve(i + 1, j, !turn, A, dp), solve(i, j - 1, !turn, A, dp));
    }
    bool PredictTheWinner(vector<int>& A) {
        int total_sum = 0;
        for(auto &it : A) {
            total_sum += it;
        }
        vector<vector<vector<int>>> dp(21, 
            vector<vector<int>> (21, vector<int> (2, -1)));
        int curr_sum = solve(0, A.size() - 1, true, A, dp);
        return total_sum - curr_sum <= curr_sum;
    }
};