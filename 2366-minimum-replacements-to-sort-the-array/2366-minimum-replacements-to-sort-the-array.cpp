class Solution {
public:
    long long minimumReplacement(vector<int>& arr) {
        int n = arr.size();
        long long res = 0;
        int prev = arr.back();
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > prev) {
                int cur = ((arr[i] - 1) / prev);
                res += cur;
                prev = arr[i] / (cur + 1);
            } else {
                prev = arr[i];
            }
        }
        return res;
    }
};