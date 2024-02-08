class Solution {
public:
    int numSquares(int n) {
        queue<array<int, 2>> q({{n, 0}});
        set<int> visit;
        visit.insert(n);
        while (!q.empty()) {
            array<int, 2> a = q.front();
            q.pop();
            if (a[0] == 0) return a[1];
            for (int i = 1; i * i <= a[0]; ++i) {
                if (visit.find(a[0] - i * i) == visit.end()) {
                    visit.insert(a[0] - i * i);
                    q.push({a[0] - i * i, a[1] + 1});
                }
            }
        }
        return -1;
    }
};