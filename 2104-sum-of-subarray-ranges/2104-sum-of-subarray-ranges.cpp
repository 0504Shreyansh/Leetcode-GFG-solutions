class Solution {
private:
    vector<int> prevSmaller(vector<int>& arr, int n) {
        vector<int> ps(n, -1);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
            while(st.size() && arr[st.top()] >= arr[i]) {
                ps[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ps;
    }
    vector<int> nextSmaller(vector<int>& arr, int n) {
        vector<int> ns(n, n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(st.size() && arr[st.top()] > arr[i]) {
                ns[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ns;
    }
    vector<int> prevGreater(vector<int>& arr, int n) {
        vector<int> pg(n, -1);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
            while(st.size() && arr[st.top()] <= arr[i]) {
                pg[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return pg;
    }
    vector<int> nextGreater(vector<int>& arr, int n) {
        vector<int> ng(n, n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(st.size() && arr[st.top()] < arr[i]) {
                ng[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ng;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> ps = prevSmaller(nums, n);
        vector<int> ns = nextSmaller(nums, n);
        vector<int> pg = prevGreater(nums, n);
        vector<int> ng = nextGreater(nums, n);        
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            long long maxi = (ng[i] - i) * (i - pg[i]);
            long long mini = (ns[i] - i) * (i - ps[i]);
            ans += (maxi - mini) * nums[i];
        }
        return ans;
    }
};