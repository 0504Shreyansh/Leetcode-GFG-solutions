class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int> mp;
        for(auto &it : tasks) {
            mp[it]++;
        }
        priority_queue<int> pq;
        queue<pair<int,int>> q;
        for(auto &it : mp) {
            pq.push(it.second);
        }
        int time = 0;
        while(pq.size() || q.size()) {
            time++;
            if(pq.size()) {
                int top = pq.top();
                pq.pop();
                if(top - 1 > 0) q.push({top - 1, time + n});
            }
            if(q.size() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};