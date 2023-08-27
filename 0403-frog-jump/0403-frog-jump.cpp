class Solution {
private:
    unordered_map<int, unordered_map<int, int>> m;
    int solve(int i, int prevSteps, vector<int>& stones) {
        int n = stones.size();
        if (i == n - 1) return true;
        if (m[i].count(prevSteps)) return m[i][prevSteps];
        int idx1 = lower_bound(begin(stones), end(stones), stones[i] + prevSteps - 1) - begin(stones);
        int idx2 = lower_bound(begin(stones), end(stones), stones[i] + prevSteps) - begin(stones);
        int idx3 = lower_bound(begin(stones), end(stones), stones[i] + prevSteps + 1) - begin(stones);
        bool ans = false;
        if (idx1 < n && idx1 > i && stones[idx1] == stones[i] + prevSteps - 1) ans |= solve(idx1, prevSteps - 1, stones);
        if (idx2 < n && idx2 > i && stones[idx2] == stones[i] + prevSteps) ans |= solve(idx2, prevSteps, stones);
        if (idx3 < n && idx3 > i && stones[idx3] == stones[i] + prevSteps + 1) ans |= solve(idx3, prevSteps + 1, stones);
        return m[i][prevSteps] = ans;
    }

public:
    bool canCross(vector<int> stones) {
        if (stones[1] != 1) return false;
        return solve(1, 1, stones);
    }
};