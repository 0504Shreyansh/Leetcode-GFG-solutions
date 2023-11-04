class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        return max((!left.empty()) ? *max_element(left.begin(), left.end()) : 0,                (!right.empty()) ? n - *min_element(right.begin(), right.end()) : 0);
    }
};