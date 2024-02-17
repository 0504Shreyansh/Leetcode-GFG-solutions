class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        multiset<int> diff;
        for (int i = 1; i < n; i++) {
            int d = heights[i] - heights[i - 1];
            if (d > 0) {
                diff.insert(d);
                if (diff.size() > ladders) {
                    bricks -= *begin(diff);
                    diff.erase(begin(diff));
                    if (bricks < 0) return i - 1;
                }
            }
        }
        return n - 1;
    }
};