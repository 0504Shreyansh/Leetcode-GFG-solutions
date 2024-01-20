class Solution {
private:
    vector<int> nextSmallerEle(vector<int> &arr, int n) {
        vector<int> nse(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) 
                st.pop();
            if (!st.empty()) 
                nse[i] = st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> prevSmallerEle(vector<int> &arr, int n) {
        vector<int> pse(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) 
                st.pop();
            if (!st.empty()) 
                pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int mod = 1e9 + 7;
        long long ans = 0;
        vector<int> pse = prevSmallerEle(arr, n);
        vector<int> nse = nextSmallerEle(arr, n);
        for (int i = 0; i < n; i++) {
            long long contribution = (nse[i] - i) * (i - pse[i]);
            ans = (ans + arr[i] * contribution) %  mod;
        }
        return ans;
    }
};