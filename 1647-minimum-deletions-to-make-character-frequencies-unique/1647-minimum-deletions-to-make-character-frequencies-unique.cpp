class Solution {
public:
    int minDeletions(string s) {
        vector<int> mp(26);
        int maxCount = 0;
        for (auto &it : s)
            maxCount = max(maxCount, ++mp[it - 'a']);
        priority_queue<int> pq;
        for (auto &it : mp)
            if (it != 0)
                pq.push(it);
        int dels = 0;
        while (pq.size()) {
            int num = pq.top();
            pq.pop();
            if (maxCount == 0) {
                dels += num;
                continue;
            }
            if (num >= maxCount) {
                dels += (num - maxCount);
                maxCount--;
            } else {
                maxCount = num - 1;
            }
        }
        return dels;
    }
};