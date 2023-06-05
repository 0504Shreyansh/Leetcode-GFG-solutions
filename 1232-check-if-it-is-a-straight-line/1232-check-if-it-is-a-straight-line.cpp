class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        int slope = (c.back()[0] - c[0][0] == 0) ? INT_MAX : (c.back()[1] - c[0][1]) / (c.back()[0] - c[0][0]);
        for (int i = 1; i < c.size(); i++) {
            int currSlope = (c[i][0] - c[i - 1][0] == 0) ? INT_MAX : (c[i][1] - c[i - 1][1]) / (c[i][0] - c[i - 1][0]);
            if(currSlope != slope) 
                return false;
        }
        return true;
    }
};