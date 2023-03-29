class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int N = prices.size();
        vector<int> dpMinPrefix(prices);
        vector<int> dpMaxSuffix(prices);
        
        for(int i = 1; i < N; i++)
            dpMinPrefix[i] = min(dpMinPrefix[i], dpMinPrefix[i-1]);
        
        for(int i = N-2; i >= 0; i--)
            dpMaxSuffix[i] = max(dpMaxSuffix[i], dpMaxSuffix[i+1]);
        
        int res = 0;
        for(int i = 0; i < N; i++)
            res = max(res, dpMaxSuffix[i]-dpMinPrefix[i]);
        
        return res;
    }
};