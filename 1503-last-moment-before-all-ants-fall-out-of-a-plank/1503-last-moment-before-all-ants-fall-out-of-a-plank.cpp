class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxLeft = 0;
        if (!left.empty()) maxLeft = *max_element(left.begin(), left.end());
        int minRight = 0;
        if (!right.empty()) minRight = n - *min_element(right.begin(), right.end());
        return max(maxLeft, minRight);
    }
};