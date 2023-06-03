class Solution {
public:
    unordered_map<int,int> dp;
    int getMinDays(int n) {
        // Base case
        if(n <= 1) {
            return 1;
        }
        
        if(dp.find(n) != dp.end()) {
            return dp[n];
        }
            
        int divideBy2 = (n % 2) + getMinDays(n / 2);
        int divideBy3 = (n % 3) + getMinDays(n / 3);
        
        return dp[n] = min({divideBy2, divideBy3}) + 1;
    }
    int minDays(int n) {
        return getMinDays(n);   // + try bfs approach
    }
};