#define ll long long
#define mod 1000000007
class Solution {
public:
    int binpow(ll a, ll b) {
        ll ans = 1;
        while (b) {
            if (b & 1)
                ans = (ans * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return ans;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(begin(nums),end(nums));
        ll ans = 0;
        int N = nums.size();
        for (int i = 0; i < N; i++) {
            auto it = upper_bound(begin(nums)+i,end(nums),target-nums[i]) - begin(nums);
            it--;
            if (it>=i && it<N) {
                ans = (ans + binpow(2, it-i)) % mod;
            }
        }
        return ans;
    }
};