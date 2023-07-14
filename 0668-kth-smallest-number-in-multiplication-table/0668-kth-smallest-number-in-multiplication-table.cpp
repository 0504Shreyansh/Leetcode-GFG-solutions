class Solution {
private:
    int count(int m, int n, int mid) {
        int cnt = 0;
        for (int i = 1; i <= m; i++)
            cnt += min(n, mid / i);
        return cnt;
    }
public:
    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m * n;
        while (low <= high) {
            int mid = (low + high) / 2;
            int cnt = count(m, n, mid);
            if(cnt < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};