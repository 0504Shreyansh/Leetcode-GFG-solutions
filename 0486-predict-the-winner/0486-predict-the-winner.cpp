class Solution {
public:
    int solve(int i, int j, bool turn, vector<int>& A) {
        if(i > j) return 0;
        if(turn) return max(A[i] + solve(i + 1, j, !turn, A), A[j] + solve(i, j - 1, !turn, A));
        return min(solve(i + 1, j, !turn, A), solve(i, j - 1, !turn, A));
    }
    bool PredictTheWinner(vector<int>& A) {
        int total_sum = 0;
        for(auto &it : A) {
            total_sum += it;
        }
        int curr_sum = solve(0, A.size() - 1, true, A);
        return total_sum - curr_sum <= curr_sum;
    }
};