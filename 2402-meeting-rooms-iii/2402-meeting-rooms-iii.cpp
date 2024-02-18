class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        sort(begin(meetings), end(meetings));
        priority_queue<int> available;
        for (int i = 0; i < n; i++) {
            available.push(-i);
        }

        int maxMeetings = 0;
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
                maxMeetings = max(maxMeetings, ++cnt[room]);
                pq.push({-endTime, -room});
            } else {
                int room = -pq.top()[1];
                long long newTime = -pq.top()[0] + endTime - meet[0];
                pq.pop();
                maxMeetings = max(maxMeetings, ++cnt[room]);
                pq.push({-newTime, -room});
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (cnt[i] == maxMeetings) {
                return i;
            }
        }
        return -1;
    }
};