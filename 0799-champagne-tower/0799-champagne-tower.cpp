class Solution {
public:
    double champagneTower(int poured, int r, int g) {
        vector<double> prev(1, poured);
        for(int i = 1; i < r+1; i++){
            vector<double> cur(i + 1, 0.00);
            for(int j = 0; j < i; j++){
                double extra = prev[j]-1.0;
                if(extra > 0){
                    cur[j] += 0.5*extra;
                    cur[j + 1] += 0.5*extra;
                }
            }
            prev = cur;
        }
        return min(1.00, prev[g]);
    }
};