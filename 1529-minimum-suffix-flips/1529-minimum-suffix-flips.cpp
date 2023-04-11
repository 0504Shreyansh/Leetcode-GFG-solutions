class Solution {
public:
    int minFlips(string target) {
        char prev = '0';
        int flips = 0;
        for (int i = 0; i < target.size(); i++) {
            if (target[i] != prev)
                flips++;
            prev = target[i];
        }
        return flips;
    }
};