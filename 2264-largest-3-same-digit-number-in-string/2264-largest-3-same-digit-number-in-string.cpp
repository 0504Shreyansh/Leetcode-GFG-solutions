class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string ans = "";
        for (int i = 1; i < n - 1; i++) {
            if (num[i - 1] == num[i] and num[i] == num[i + 1]) {
                ans = max(ans, num.substr(i - 1, 3));
            }
        }
        return ans;
    }
};