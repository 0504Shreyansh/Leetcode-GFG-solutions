class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        
        int res = 0;
        int N = satisfaction.size();
        sort(satisfaction.rbegin(),satisfaction.rend());
        for(int i = 0; i < N; i++) {
            int cur = 0, k = i+1;
            for(int j = 0; j <= i; j++) {
                cur += (k--)*satisfaction[j];
            } 
            res = max(res, cur);
        }
        return res;
        
    }
};