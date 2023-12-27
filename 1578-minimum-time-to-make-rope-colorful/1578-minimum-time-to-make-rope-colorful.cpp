class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0, n = colors.size();
        for (int i = 0; i < n; i++) {
            int j = i, maxTime = 0;
            while (j < n && colors[i] == colors[j]) {
                ans += neededTime[j];
                maxTime = max(maxTime, neededTime[j]);
                j++;
            }
            ans -= maxTime;
            i = j - 1;
        }
        return ans;
    }
};