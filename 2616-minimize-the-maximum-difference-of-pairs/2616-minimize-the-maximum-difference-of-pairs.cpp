class Solution {
private:
    bool isPossible(vector<int>& A, int p, int mid) {
        int cnt = 0;
        for (int i = 1; i < A.size(); i++) {
            if (mid >= A[i] - A[i - 1]) {
                p--;
                i++;
            } 
            if (p == 0) return true;
        }
        return false;
    }
public:
    int minimizeMax(vector<int>& A, int p) {
        sort(begin(A),end(A));
        int ans = 1e9+1;
        int low = 0;
        int high = A.back() - A[0];
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(A, p, mid)) {
                ans = mid;
                high = mid - 1;                
            } else {
                low = mid + 1;
            }
        }
        return (ans == 1e9+1) ? 0 : ans;
    }
};