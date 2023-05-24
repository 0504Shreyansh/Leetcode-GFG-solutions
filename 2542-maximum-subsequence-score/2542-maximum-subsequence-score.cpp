class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> pairs;
        for(int i = 0; i < n; i++) {
            pairs.push_back({nums2[i], nums1[i]});
        }
        sort(rbegin(pairs),rend(pairs));
        long long ans = 0;
        long long cur = 0;
        priority_queue<int> pq;
        for(int i = 0; i < k - 1; i++) {
            cur += pairs[i].second;
            pq.push(-pairs[i].second);
        }
        
        // decide for the minimum value 
        // all greater values have been considered 
        // now its the deciding minimum and maximise it
        for(int i = k - 1; i < n; i++) { 
            // try to make current maximum 
            cur += pairs[i].second;
            pq.push(-pairs[i].second);
            // maximise the ans by considering pair[i].first as the minimum 
            ans = max(ans, cur * pairs[i].first);
            // minHeap to always give us the prev smallest to subtract later
            cur -= -pq.top();
            pq.pop();
        }
        return ans;
    }
};