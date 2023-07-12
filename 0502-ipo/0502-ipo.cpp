class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> pairs;
        priority_queue<int> pq;
        for(int i = 0; i < n; i++) {
            pairs.push_back({capital[i], profits[i]});
        }
        sort(begin(pairs),end(pairs));
        int i = 0;
        while(k--) {
            while(i < n && pairs[i].first <= w) {
                pq.push(pairs[i++].second);
            }
            if(pq.empty()) break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};