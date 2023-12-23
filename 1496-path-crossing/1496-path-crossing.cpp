class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int, int>, bool> found;
        int x = 0, y = 0;
        found[{0, 0}] = 1;
        for (auto &it : path) {
            if (it == 'N') y++;
            else if (it == 'E') x++;
            else if (it == 'W') x--;
            else y--;
            if (found[{x, y}]) return true;
            found[{x, y}] = 1;
        }
        return false;
    }
};