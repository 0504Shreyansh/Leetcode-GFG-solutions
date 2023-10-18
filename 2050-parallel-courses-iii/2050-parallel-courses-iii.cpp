class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> A[n];
        vector<int> in(n);
        for (auto &r : relations) {
            A[r[0] - 1].push_back(r[1] - 1);
            in[r[1] - 1]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        vector<int> timer(time);
        int ans = *max_element(begin(time), end(time));
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (int &v : A[u]) {
                timer[v] = max(timer[v], timer[u] + time[v]);
                ans = max(ans, timer[v]);
                if (--in[v] == 0) {
                    q.push(v);
                }
            }
        }
        return ans;
    }
};