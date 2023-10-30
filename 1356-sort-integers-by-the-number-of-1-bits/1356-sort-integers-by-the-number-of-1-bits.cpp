class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> bits[32];
        for (int &num : arr) {
            int bitCount = __builtin_popcount(num);
            bits[bitCount].push_back(num);
        }
        vector<int> ans;
        for (auto &it : bits) {
            sort(begin(it), end(it));
            for (auto &x : it) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};