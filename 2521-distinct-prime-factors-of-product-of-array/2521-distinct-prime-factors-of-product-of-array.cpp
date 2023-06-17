class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int res = 0;
        set<int> factors;
        for(auto it : nums) {
            for(int j = 2; j * j <= it; j++) {
                if(it % j == 0) {
                    factors.insert(j);
                    while(it % j == 0)
                        it /= j;
                }
            }
            if(it > 1) {
                factors.insert(it);
            }
        }
        return factors.size();
    }
};