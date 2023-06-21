class Solution {
public:
    long long findSum(vector<pair<int,int>>& pairs) {
        long long res = 0;
        for(auto &it : pairs) {
            int cost = it.second;   
            res += cost;
        }
       return res;
    }
    
    int findMedian(vector<pair<int,int>>& pairs) {
        long long sum = findSum(pairs);
        long long curr_sum = 0;
        int median = pairs[0].first;
        for(int i = 0; i < pairs.size() && curr_sum < (sum + 1) / 2; i++) {
            curr_sum += pairs[i].second;
            median = pairs[i].first;
        }
        return median;
    }
    
    long long findCost(vector<pair<int,int>>& pairs, int median) {
        long long res = 0;
        for(auto &it : pairs) {
            int num = it.first;
            int cost = it.second;
            res += 1LL * abs(num - median) * 1LL * cost;
        }
        return res;
    }
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<int,int>> pairs;
        for(int i = 0; i < n; i++) {
            pairs.push_back({nums[i], cost[i]});
        }
        sort(begin(pairs),end(pairs));
        
        int median = findMedian(pairs);
        
        return findCost(pairs, median);
    }   
};