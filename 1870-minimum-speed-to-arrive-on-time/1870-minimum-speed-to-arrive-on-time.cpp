class Solution {
private:
    bool isPossible(vector<int>& dist, double hour, int mid) {
        double ans = 0.0;
        for (int i = 0; i < dist.size() - 1; i++)
            ans += ceil(((double)dist[i] / mid));
        ans += ((double)dist.back()) / mid;
        return ans <= hour;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1;
        int high = 1e9;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (isPossible(dist, hour, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // cout << low <<' ' << high << ' ' << ans << endl;
        return ans == -1 ? -1 : ans;
    }
};