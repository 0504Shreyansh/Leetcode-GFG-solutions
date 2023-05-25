class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0 || n >= k + maxPts)
            return 1;
        vector<double> dp(n + 1, 0.0);
        dp[0] = 1;
        double curSum = 1;
        
        for(int i = 1; i <= n; i++) {
            dp[i] += curSum / (double)maxPts;
            if(i < k)
                curSum += dp[i];
            if(i - maxPts >= 0)
                curSum -= dp[i - maxPts];
        }
        
        // count all probabilities
        double ans = 0;
        for(int i = k; i <= n; i++) 
            ans += dp[i];
        return ans;
    }
};