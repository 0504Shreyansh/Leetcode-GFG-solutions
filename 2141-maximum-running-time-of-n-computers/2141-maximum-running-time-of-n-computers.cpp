class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(begin(batteries),end(batteries));
        long long sum = 0;
        for (auto &it : batteries) {
            sum += it;
        }
        int i = batteries.size() - 1;
        while (batteries[i] > sum / n) {
            sum -= batteries[i--];
            n--;
        }
        return sum / n;
    }
};