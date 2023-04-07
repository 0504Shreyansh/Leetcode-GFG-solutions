class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        vector<long long> times(60);
        for(auto t : time)
            times[t % 60]++;
        
        long long res = 0;
        int i = 1, j = 59;
        while(i < j) {
            res += (times[i] * times[j]);
            i++; j--;
        }
        
        res += (times[30]*(times[30]-1))/2;
        res += (times[0]*(times[0]-1))/2;
        
        return res;
    }
};