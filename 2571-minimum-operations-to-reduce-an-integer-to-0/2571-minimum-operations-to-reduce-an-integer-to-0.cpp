class Solution {
public:
    int minOperations(int n) {

        vector<int> powerOf2;
        for(int i = 0; i < 20; i++)
            powerOf2.push_back(1<<i);
        
        int res = 0;
        while(n != 0) 
        {
            int ub = upper_bound(powerOf2.begin(),powerOf2.end(),n) - powerOf2.begin();
            // No overflow or anything bcoz range if upto 1e5
            int lowerPowerOf2 = powerOf2[ub-1];
            int greaterPowerOf2 = powerOf2[ub];
            
            if(greaterPowerOf2 - n > n - lowerPowerOf2)
                n -= lowerPowerOf2;
            else 
                n = greaterPowerOf2 - n;
            
            res++;
        }
        
        return res;
    }
};