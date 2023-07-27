class Solution {
private:
    bool isPossible(vector<int>& batteries, int n, long long mid) {
        long long cur = 0;
        for (auto &it : batteries) {
            if (it > mid) cur += mid;
            else cur += it;
        }
        return (cur >= mid * n);
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long low = 1;
        long long high = 0;
        sort(begin(batteries),end(batteries));
        for (auto &it : batteries) {
            high += it;
        }
        high /= n;
        long long ans = -1;
        while (low <= high) {
            long long mid = (low + high) >> 1;
            if (isPossible(batteries, n, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};