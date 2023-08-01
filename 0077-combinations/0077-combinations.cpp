class Solution {
private:
    void f(int n, int k, int prev, vector<int>& t, vector<vector<int>>& ans) {
        if (k == 0) {
            ans.push_back(t);
        } else {
            for (int i = prev; i <= n; i++) {       
                t.push_back(i);
                f(n, k - 1, i + 1, t, ans);
                t.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> t;
        vector<vector<int>> ans;
        f(n, k, 1, t, ans);
        return ans;
    }
};