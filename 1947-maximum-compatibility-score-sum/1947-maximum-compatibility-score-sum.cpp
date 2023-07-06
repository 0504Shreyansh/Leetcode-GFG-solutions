class Solution {
public:
    int solve(int i, int mask, vector<vector<int>>& students, vector<vector<int>>& mentors, vector<vector<int>>& dp) {
        int n = mentors.size(), m = mentors[0].size();
        if(i >= n) {
            return 0;
        }
        if(dp[i][mask] != -1) {
            return dp[i][mask];   
        }
        int maxScore = 0, currScore;
        for(int j = 0; j < n; ++j) {
            if(!(mask & (1 << j))) {
                int score = 0;
                for(int k = 0; k < m; ++k) {
                    if(students[i][k] == mentors[j][k]) {
                        score++;
                    }
                }
                currScore = score + solve(i + 1, mask | (1 << j), students, mentors, dp);
                maxScore = max(maxScore, currScore);
            }
        }
        return dp[i][mask] = maxScore;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        vector<vector<int>> dp(students.size(),
            vector<int> ((1 << students.size()), -1));
        return solve(0, 0, students, mentors, dp);
    }
};