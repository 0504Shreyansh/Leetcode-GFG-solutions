class Solution {
private:
    vector<long long> leftSmaller(vector<int>& arr, int n) {
        vector<long long> left(n);
        stack<pair<int, long long>> st;
        for(int i = 0; i < n; i++) {
            int val = 1;
            while(st.size() && st.top().first >= arr[i]) { 
                val += st.top().second;
                st.pop();
            }
            left[i] = val;
            st.push({arr[i], val});
        }
        return left;
    }
    vector<long long> rightSmaller(vector<int>& arr, int n) {
        vector<long long> right(n);
        stack<pair<int, long long>> st;
        for(int i = n - 1; i >= 0; i--) {
            int val = 1;
            while(st.size() && st.top().first > arr[i]) {
                val += st.top().second;
                st.pop();
            }
            right[i] = val;
            st.push({arr[i], val});
        }
        return right;
    }
    
public:
    // count the left and right contribution of each value 
    // of the arr as a minimum ele of an subarray
    const int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<long long> left = leftSmaller(arr, n);
        vector<long long> right = rightSmaller(arr, n);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = (ans + arr[i] * left[i] * right[i]) % mod;
        }
        return ans;
    }
};