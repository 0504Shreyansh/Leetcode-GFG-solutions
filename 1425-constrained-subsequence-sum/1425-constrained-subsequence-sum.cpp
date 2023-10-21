class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = nums[0];
        priority_queue<pair<int, int>> pq;
        pq.push({nums[0], 0});
        for (int i = 1; i < n; i++) {
            while (pq.size() && i - pq.top().second > k)
                pq.pop();
            ans = max(ans, max(pq.top().first, 0) + nums[i]);
            pq.push({max(pq.top().first, 0) + nums[i], i});
        }
        return ans;
    }
};