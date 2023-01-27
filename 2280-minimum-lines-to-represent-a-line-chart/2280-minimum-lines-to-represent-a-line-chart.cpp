class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int n = stockPrices.size();
        if(n==1) return 0;
        sort(stockPrices.begin(),stockPrices.end());
        vector<pair<long,long>> slopes;
        for(int i=1;i<n;i++) {
            int x1=stockPrices[i-1][0], y1=stockPrices[i-1][1];
            int x2=stockPrices[i][0], y2=stockPrices[i][1];
            slopes.push_back({(x2-x1),(y2-y1)});
        }
        // for(auto i:slopes) cout<<i<<' '; cout<<endl;
        int numer_of_lines = 1;
        for(int i=1;i<slopes.size();i++) {
            auto curr_slope = slopes[i];
            auto prev_slope = slopes[i-1];
            if(curr_slope.first*prev_slope.second != curr_slope.second*prev_slope.first) {
                // prev_slope = curr_slope; 
                numer_of_lines++;
            }
        }
        return numer_of_lines;
    }
};