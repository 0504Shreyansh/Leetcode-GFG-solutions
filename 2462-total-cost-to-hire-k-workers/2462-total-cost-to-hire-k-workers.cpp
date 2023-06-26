class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        int low = candidates - 1;
        int high = max(low + 1, n - candidates);
        priority_queue<pair<int,int>> pq;
        
        // Consider first and last 'candidates' workers
        // Be careful to not cross each other pointers
        for(int i = 0; i <= low; i++) {
            pq.push({-costs[i], -i});
        }   
        for(int i = n - 1; i >= high; i--) {
            pq.push({-costs[i], -i});
        }
        
        long long total_cost = 0;
        while(pq.size() && k--) {
            auto curr = pq.top();
            pq.pop();
            int curr_cost = -curr.first;
            int index = -curr.second;
            total_cost += curr_cost;
            
            // Adjust the window by considering the corresponding next index
            // (if possible)
            if(index >= high) {
                high--;
                if(low < high) pq.push({-costs[high], -high});
            } else {
                low++;
                if(low < high) pq.push({-costs[low], -low});
            }
        }
        return total_cost;
    }
};