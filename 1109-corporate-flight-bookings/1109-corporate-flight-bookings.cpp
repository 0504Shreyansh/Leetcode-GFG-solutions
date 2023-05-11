class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> A(n);
        for (auto B : bookings)
        {
            int l = B[0];
            int r = B[1];
            int value = B[2];
            
            // Mark start value
            A[l - 1] += value;
            
            // Dismark end value
            if (r < n)
                A[r] -= value;
        }
        for (int i = 1; i < n; i++)
            A[i] += A[i - 1];
        return A;
    }
};