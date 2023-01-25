class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        
        if(k==0) {
            if(nums1==nums2)
                return 0;
            return -1;
        }
        long long pos = 0, neg = 0;
        int n = nums1.size();
        for(int i=0;i<n;i++) {
            int diff = abs(nums1[i]-nums2[i]);
            if(diff%k) return -1;
            if(nums1[i]>nums2[i]) pos += diff/k;
            else neg += diff/k;
        }
        
        return (pos==neg) ? pos:-1;
    }
};