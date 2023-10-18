class Solution {
private:    
    vector<int> prevSmaller(vector<int>& heights, int n) {
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (st.size() && heights[st.top()] >= heights[i])
                st.pop();
            ans[i] = (st.size()) ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }
    vector<int> nextSmaller(vector<int>& heights, int n) {
        vector<int> ans(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() && heights[st.top()] >= heights[i])
                st.pop();
            ans[i] = (st.size()) ? st.top() : n;
            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prev = prevSmaller(heights, n);
        vector<int> next = nextSmaller(heights, n);
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int height = heights[i];
            int width = next[i] - prev[i] - 1;
            maxArea = max(maxArea, height * width);
        }
        return maxArea;
    }
};