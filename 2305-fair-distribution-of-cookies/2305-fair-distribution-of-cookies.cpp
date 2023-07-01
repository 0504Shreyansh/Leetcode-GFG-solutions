class Solution {
public:
    int ans = INT_MAX;
    void solve(int i, int n, vector<int>& cookies, int k, vector<int>& dist) {
        if(i >= n) {        
            int maxi = *max_element(begin(dist),end(dist));
            ans = min(ans, maxi); 
            return ;
        }

        for(int j = 0; j < k; ++j) {
            dist[j] += cookies[i];
            solve(i + 1, n, cookies, k, dist);
            dist[j] -= cookies[i];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> dist(k);
        solve(0, cookies.size(), cookies, k, dist);
        return ans;
    }
};