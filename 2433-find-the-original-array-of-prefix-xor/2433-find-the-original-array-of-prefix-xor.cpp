class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans(pref);
        int n = pref.size();
        for (int i = 1; i < n; i++) {
            ans[i] = pref[i] ^ pref[i - 1];
        }
        return ans;
    }
};