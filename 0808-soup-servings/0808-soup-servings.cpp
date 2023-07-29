class Solution {
private:
    map<pair<int, int>, double> dp;
    double solve(int n, int m) {
        if (n <= 0 && m > 0) return 1.0;
        if (n <= 0 && m <= 0) return 0.5;
        if (n > 0 && m <= 0) return 0.0;
        if (dp.find({n, m}) != dp.end()) return dp[{n, m}];
        return dp[{n, m}] = (solve(n - 100, m) + solve(n - 75, m - 25) + solve(n - 50, m -  50) + solve(n - 25, m - 75)) / 4.0;
    }
public:
    double soupServings(int n) {
        return (n < 4801) ? solve(n, n) : 1.0;
    }
};