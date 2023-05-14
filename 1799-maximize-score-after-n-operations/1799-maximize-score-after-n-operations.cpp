class Solution {
public:
    int solve(int mask, int countOfOp, int N, vector<int>& nums, vector<int>& dp) {     
        // Performed all operations
        if(countOfOp >= N / 2) {
            return 0;
        }
        
        if(dp[mask] != -1) {
            return dp[mask];
        }
        
        int maxScore = 0;
        for(int i = 0; i < N; i++) {
            if(((mask >> i) & 1) == 1) {
                continue;   // Already taken -> skip
            }
            for(int j = i + 1; j < N; j++) {
                if(((mask >> j) & 1) == 1) {
                    continue;   // Already taken -> skip
                }
                
                // Update mask -> mask + i(taken) + j(taken)
                int newMask = mask | (1 << i) | (1 << j);
                
                // Calculate the current score
                int curScore = (countOfOp + 1) * __gcd(nums[i], nums[j]);
                
                // Recursive call for further score calculation
                int remainingScore = solve(newMask, countOfOp + 1, N, nums, dp);
                maxScore = max(maxScore, curScore + remainingScore);
            }
        }
        
        return dp[mask] = maxScore;
    }
    int maxScore(vector<int>& nums) {
        int N = nums.size();
        // 2 ^ N -> number of unique possible combiantions of take or notTake
        int maskValue = (1 << N);  // 2 ^ N
        vector<int> dp(maskValue, -1);
        return solve(0, 0, N, nums, dp);
    }
};