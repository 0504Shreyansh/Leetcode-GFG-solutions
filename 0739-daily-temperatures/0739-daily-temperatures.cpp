class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<array<int, 2>> st;
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top()[0] <= temperatures[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top()[1] - i;
            }
            st.push({temperatures[i], i});
        }
        return ans;
    }
};