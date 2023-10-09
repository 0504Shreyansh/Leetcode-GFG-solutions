class Solution {
public:
    vector<int> searchRange(vector<int>& A, int k) {
        int lidx = lower_bound(begin(A), end(A), k) - begin(A);
        if (!(lidx >= 0 && lidx < A.size() && A[lidx] == k)) 
            return {-1, -1};
        int uidx = upper_bound(begin(A), end(A), k) - begin(A);
        return {lidx, uidx - 1};
    }
};