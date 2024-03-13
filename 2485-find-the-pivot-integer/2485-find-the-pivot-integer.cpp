class Solution {
public:
    int pivotInteger(int n) {
        int low = n / 2, high = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            int sum = (mid * (mid + 1)) / 2, sum2 = (n * (n + 1)) / 2 - (mid * (mid - 1)) / 2;
            if (sum == sum2) return mid;
            if (sum < sum2) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};