class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> mp;
        int n = cards.size();
        int ans = 1e6;
        for(int j = 0; j < n; j++) {
            if(mp.find(cards[j]) != mp.end()) {
                ans = min(ans, j - mp[cards[j]] + 1);
            }
            mp[cards[j]] = j;
        }
        return (ans == 1e6) ? -1 : ans;
    }
};