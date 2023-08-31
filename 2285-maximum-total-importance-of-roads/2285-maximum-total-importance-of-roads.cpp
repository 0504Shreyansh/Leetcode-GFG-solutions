class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> G[n];
        for (auto &it : roads) {
            G[it[0]].push_back(it[1]);
            G[it[1]].push_back(it[0]);
        }
        priority_queue<pair<long long, int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({G[i].size(), i});
        }
        long long num = n;
        long long answer = 0;
        while (pq.size()) {
            answer += pq.top().first * num;
            num--;
            pq.pop();
        }
        return answer;
    }
};