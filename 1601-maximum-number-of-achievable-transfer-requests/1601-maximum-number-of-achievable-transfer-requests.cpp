class Solution {
private:
    void solve(int i, int n, vector<vector<int>>& requests, unordered_map<int, int>& mp, int picked, int &ans) {
        if(i >= requests.size()) {
            if(mp.size() == 0) {
                ans = max(ans, picked);
            }
            return ;
        }

        // not consider
        solve(i + 1, n, requests, mp, picked, ans);

        // consider
        if(--mp[requests[i][0]] == 0) mp.erase(requests[i][0]);
        if(++mp[requests[i][1]] == 0) mp.erase(requests[i][1]);
        solve(i + 1, n, requests, mp, picked + 1, ans);
        if(++mp[requests[i][0]] == 0) mp.erase(requests[i][0]);
        if(--mp[requests[i][1]] == 0) mp.erase(requests[i][1]);
    }
    
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int ans = 0;
        unordered_map<int, int> mp;
        solve(0, n, requests, mp, 0, ans);
        return ans;
    }
};