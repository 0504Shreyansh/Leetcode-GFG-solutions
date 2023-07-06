class Solution {
public:
    int solve(int i, int mask, vector<vector<int>>& students, vector<vector<int>>& mentors, vector<int>& dp) {
        int n = mentors.size(), m = mentors[0].size();
        if(i >= n) {
            return 0;
        }
        if(dp[mask] != -1) {
            return dp[mask];   
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
        return dp[mask] = maxScore;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
    
        vector<int> dp(1 << students.size(), -1);
        return solve(0, 0, students, mentors, dp);
    }
};