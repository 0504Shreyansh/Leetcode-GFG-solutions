class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        sort(begin(meetings), end(meetings));
        priority_queue<int> available;
        for (int i = 0; i < n; i++) {
            available.push(-i);
        }

        vector<int> cnt(n);
        priority_queue<array<long long, 2>> pq;
        for (auto &meet : meetings) {
            int endTime = meet[1];
            while (!pq.empty() && -pq.top()[0] <= meet[0]) {
                available.push(pq.top()[1]);
                pq.pop();
            }
            if (!available.empty()) {
                int room = -available.top();
                available.pop();
                ++cnt[room];
                pq.push({-endTime, -room});
            } else {
                int room = -pq.top()[1];
                long long newTime = -pq.top()[0] + endTime - meet[0];
                // cout << room << ' ' << -pq.top()[0] << endl;
                pq.pop();
                ++cnt[room];
                pq.push({-newTime, -room});
            }
        }
        
        int ans = -1, curr = 0;
        for (int i = 0; i < n; i++) {
            if (curr < cnt[i]) {
                curr = cnt[i];
                ans = i;
            }
        }
        return ans;
    }
};