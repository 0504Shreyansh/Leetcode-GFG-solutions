class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> mp;
        int maxCount = 0;
        for (auto &it : s)
            maxCount = max(maxCount, ++mp[it]);
        priority_queue<int> pq;
        for (auto &it : mp)
            pq.push(it.second);
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