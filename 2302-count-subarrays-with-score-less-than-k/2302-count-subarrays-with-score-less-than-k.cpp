class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        long long sum = 0, ans = 0;
        int i = 0, j = 0, n = nums.size();
        
        while(j<n) {
            sum += nums[j];
            //shrink the window if the prod >= k
            while(sum*(j-i+1)>=k && i<=j) 
                sum -= nums[i++];
            //Update and add answer with the window size
            if(sum*(j-i+1)<k) 
                ans += (j-i+1);
            // cout<<i<<' '<<j<<endl;
            j++;
        }
        
        return ans;
    }
};