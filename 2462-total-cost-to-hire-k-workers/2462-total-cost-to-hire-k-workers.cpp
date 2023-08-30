class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long totCost = 0;
        priority_queue<pair<int, int>> pq;
        int low = candidates - 1;
        int high = max(low + 1, n - candidates);
        for (int i = 0; i <= low; i++) {
            pq.push({-costs[i], -i});
        }
        for (int i = n - 1; i >= high; i--) {
            pq.push({-costs[i], -i});
        }
        while (k--) {
            auto cur = pq.top();
            pq.pop();
            int cost = -cur.first;
            int idx = -cur.second;
            totCost += cost;
            if (idx >= high) {
                if (low < --high) pq.push({-costs[high], -high});
            } else {
                if (++low < high) pq.push({-costs[low], -low});
            }
        }
        return totCost;
    }
};