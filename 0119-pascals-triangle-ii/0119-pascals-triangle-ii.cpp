class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev = {1};
        for (int i = 1; i <= rowIndex; i++) {
            vector<int> curr(i + 1, 1);
            for (int j = 1; j < i; j++) {
                curr[j] = prev[j] + prev[j - 1];
            }
            prev = curr;
        }
        return prev;
    }
};