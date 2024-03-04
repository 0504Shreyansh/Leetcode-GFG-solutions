class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(begin(tokens), end(tokens));
        int i = 0, j = tokens.size() - 1, score = 0, ans = 0;
        while (i <= j) {
            if (power >= tokens[i]) {
                power -= tokens[i++];
                score++;
                ans = max(ans, score);
            } else if (score > 0) {
                power += tokens[j--];
                score--;
            } else {
                break;
            }
        }
        return ans;
    }
};