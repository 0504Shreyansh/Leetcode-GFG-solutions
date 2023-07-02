class Solution {
private:
    int ans = 0;
    void solve(int i, vector<vector<int>>& requests, unordered_map<int, int>& mp, int picked) {
        if(i >= requests.size()) {
            if(mp.size() == 0) {
                ans = max(ans, picked);
            }
            return ;
        }

        // not consider
        solve(i + 1, requests, mp, picked);

        // consider
        if(--mp[requests[i][0]] == 0) mp.erase(requests[i][0]);
        if(++mp[requests[i][1]] == 0) mp.erase(requests[i][1]);
        solve(i + 1, requests, mp, picked + 1);
        if(++mp[requests[i][0]] == 0) mp.erase(requests[i][0]);
        if(--mp[requests[i][1]] == 0) mp.erase(requests[i][1]);
    }
    
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        unordered_map<int, int> mp;
        solve(0, requests, mp, 0);
        return ans;
    }
};