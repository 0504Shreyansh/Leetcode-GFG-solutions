class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        int n = nums.size();
        int maxi = INT_MIN, mini = INT_MAX;
        priority_queue<int> pq;
        
        for(auto &x : nums) {
            while(x%2)
                x *= 2;
            maxi = max(maxi, x);
            mini = min(mini, x);
            pq.push(x);
        }
        int ans = maxi - mini;
        
        while(pq.top()%2==0) {
            int top = pq.top();
            pq.pop();
            ans = min(ans, top-mini);
            top /= 2;
            mini = min(mini, top);
            pq.push(top);
        }
        
        ans = min(ans, pq.top()-mini);
        return ans;
        
    }
};