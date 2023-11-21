class Solution {
private:
    int rev(int num) {
        int ans = 0;
        while (num != 0) {
            ans = ans * 10 + (num % 10);
            num /= 10;
        }
        return ans;
    }
public:
    int countNicePairs(vector<int>& nums) {
        const int mod = 1e9 + 7;
        map<int, int> mp;
        int res = 0;
        for (auto &num : nums) {
            res += mp[num - rev(num)]++;
            res %= mod;
        }
        return res;
    }
};