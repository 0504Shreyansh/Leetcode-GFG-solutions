class Solution {
private:
    vector<int> prevSmaller(vector<int>& A) {
        int n = A.size();
        stack<int> st;
        vector<int> p(n, -1);
        for(int i = 0; i < n; i++) {
            while(st.size() && A[st.top()] >= A[i]) st.pop();
            if(st.size()) p[i] = st.top();
            st.push(i);
        }
        return p;
    } 
    vector<int> nextSmaller(vector<int>& A) {
        int n = A.size();
        stack<int> st;
        vector<int> p(n, n);
        for(int i = n - 1; i >= 0; i--) {
            while(st.size() && A[st.top()] >= A[i]) st.pop();
            if(st.size()) p[i] = st.top();
            st.push(i);
        }
        return p;
    } 
    int largestArea(vector<int>& A) {
        int n = A.size();
        vector<int> prev = prevSmaller(A);
        vector<int> next = nextSmaller(A);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int height = A[i];
            int width = next[i] - prev[i] - 1;
            ans = max(ans, height * width);
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> A(matrix[0].size(), 0);
        int ans = 0;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] == '1') A[j]++;
                else A[j] = 0;
            }
            int curArea = largestArea(A);
            ans = max(ans, curArea);
        }
        return ans;
    }
};