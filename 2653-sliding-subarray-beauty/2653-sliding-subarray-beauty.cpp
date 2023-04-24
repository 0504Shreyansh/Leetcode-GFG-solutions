class Solution {
public:
    vector<int> solve(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> res;
        
        // Store the negative numbers in a vector with their freq
        vector<int> freq(51);
        for(int i = 0; i < k; i++) {
            if(nums[i] < 0) 
                freq[-nums[i]]++;
        }

        // Loop for (n-k+1) times and find out the xth smallest no.
        // every time maintaing k size window
        for(int i = k-1; i < n; i++) {
            int count = 0;
            int ans = 0;
            for(int j = 50; j >= 0; j--) {
                count += freq[j];
                if(count >= x) {
                    ans = -j;
                    break;
                }
            }
            res.push_back(ans);
            if(nums[i-k+1] < 0) freq[-nums[i-k+1]]--;
            if(i+1<n && nums[i+1]<0) freq[-nums[i+1]]++;
        }
        return res;
    }
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        return solve(nums, k, x);
    }
};