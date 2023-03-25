class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int N = nums.size();
        int ans = 0;
        int PosSum = 0, NegSum = 0;
        vector<int> MaxPosSum(N);
        vector<int> MaxNegSum(N);
        for(int i = 0; i < N; i++) {
            PosSum += nums[i];
            NegSum += nums[i];
            // Kadane's algorithm for maxPos Sum and minNegSum 
            if(PosSum < 0) PosSum = 0;
            if(NegSum > 0) NegSum = 0;
            MaxPosSum[i] = PosSum;
            MaxNegSum[i] = NegSum;
            ans = max({ans, MaxPosSum[i], -MaxNegSum[i]});
        }

        return ans;
    }
};