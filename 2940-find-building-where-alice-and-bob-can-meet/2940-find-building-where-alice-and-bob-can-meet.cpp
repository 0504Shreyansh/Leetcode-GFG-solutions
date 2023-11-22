class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        stack<int> st;
        int n = heights.size();
        vector<int> nextGreater(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] <= heights[i]) 
                st.pop();
            if (!st.empty())
                nextGreater[i] = st.top();
            st.push(i);
        }
        
        vector<int> res;
        for (auto &q : queries) {
            int idx1 = nextGreater[q[0]], idx2 = nextGreater[q[1]];
            if (q[0] > q[1]) swap(q[0], q[1]);
            if (q[0] == q[1]) {
                res.push_back(q[0]);
            } else {
                 if (heights[q[0]] < heights[q[1]]) {
                    res.push_back(q[1]);
                } else {
                    if (idx1 != -1 && idx2 != -1) {
                        int idx = max(idx1, idx2);
                        while (idx != -1 && heights[idx] < heights[q[0]]) {
                            idx = nextGreater[idx];
                        }
                        res.push_back(idx);
                    } else {
                        res.push_back(-1);
                    }
                }
            }
        }
        return res;
    }
};