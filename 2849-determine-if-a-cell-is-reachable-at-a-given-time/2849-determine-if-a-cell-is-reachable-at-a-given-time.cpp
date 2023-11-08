class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dist = max(abs(sx - fx), abs(sy - fy));
        return (!(dist == 0 && t == 1) && (dist <= t));
    }
};