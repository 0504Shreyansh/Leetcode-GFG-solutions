class Solution {
private:
    bool isValid(int a, int b, int n, int m) {
        return (0 <= a && a < n && 0 <= b && b < m);
    }
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        vector<vector<int>> ans(n, vector<int> (m));
        int dxy[3] = {-1, 0, 1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int value = 0, count = 0;
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        if (isValid(i + dxy[x], j + dxy[y], n, m)) {
                            value += img[i + dxy[x]][j + dxy[y]];
                            count++;
                        }
                    }
                }
                ans[i][j] = (value / count);
            }
        }
        return ans;
    }
};