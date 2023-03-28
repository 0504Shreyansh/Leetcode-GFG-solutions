class Solution {
public:
    int f(int i, vector<int>& days, vector<int>& costs, vector<int>& dp) {
        int n = days.size();
        if(i >= n || i == -1) 
            return 0;
        if(dp[i] != -1) 
            return dp[i];
        
        int idx1 = -1, idx2 = -1;
        for(int j = i+1; j < n; j++) {
            if(days[j] >= days[i] + 7) {
                idx1 = j; break;
            }
        }
        for(int j = i+1; j < n; j++) {
            if(days[j] >= days[i] + 30) {
                idx2 = j; break;
            }
        }
        int oneDayTicket = costs[0] + f(i+1, days, costs, dp);
        int oneWeekTicket = costs[1] + f(idx1, days, costs, dp);
        int oneMonthTicket = costs[2] + f(idx2, days, costs, dp);
        
        return dp[i] = min({oneDayTicket, oneWeekTicket, oneMonthTicket});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n = days.size();
        vector<int> dp(n+1, -1);
        return f(0, days, costs, dp);
        
    }
};