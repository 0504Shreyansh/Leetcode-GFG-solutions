class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> res;
        set<pair<int, int>> found;
        priority_queue<pair<int, pair<int,int>>> pq;
        pq.push({-(nums1[0] + nums2[0]), {0, 0}});
        found.insert({0, 0});
        while(k-- && pq.size()) {
            auto curr = pq.top();
            pq.pop();
            int i = curr.second.first;
            int j = curr.second.second;
            res.push_back({nums1[i], nums2[j]});
            if(i + 1 < n && !found.count({i + 1, j})) {
                found.insert({i + 1, j});
                pq.push({-(nums1[i + 1] + nums2[j]), {i + 1, j}});
            }
            if(j + 1 < m && !found.count({i, j + 1})) {
                found.insert({i, j + 1});
                pq.push({-(nums1[i] + nums2[j + 1]), {i, j + 1}});
            }
        } 
        return res;
    }
};