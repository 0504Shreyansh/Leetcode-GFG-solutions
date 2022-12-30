class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        
        int n = satisfaction.size();
        sort(satisfaction.rbegin(),satisfaction.rend());
        int ans = 0;
        for(int i=0;i<satisfaction.size();i++) {
            int curr = 0, k = satisfaction.size();
            for(int j=0;j<satisfaction.size();j++) {
                curr += k*(satisfaction[j]);
                k--;
            }
            ans = max(ans,curr);
            satisfaction.pop_back();
        }
        
        return ans;
    }
};