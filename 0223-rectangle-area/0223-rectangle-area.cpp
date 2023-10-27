class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int x = max(ax1, bx1);
        int xx = min(ax2, bx2);
        int y = max(ay1, by1);
        int yy = min(ay2, by2);
        int a1 = abs(ax1 - ax2) * abs(ay1 - ay2);
        int a2 = abs(bx1 - bx2) * abs(by1 - by2);
        if (ax1 < bx2 && ax2 <= bx1) return a1 + a2;
        if (bx1 < ax2 && bx2 <= ax1) return a1 + a2;
        if (by1 < ay2 && by2 <= ay1) return a1 + a2;
        if (ay1 < by2 && ay2 <= by1) return a1 + a2;
        int overlap =  abs(x - xx) * abs(y - yy);
        return a1 + a2 - overlap;
    }
};