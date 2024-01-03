class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, n = bank.size(), prev = 0;
        for (auto &B : bank) {
            int curr = count(begin(B), end(B), '1');
            if (curr != 0) {
                if (prev == 0) prev = curr;
                else {
                    ans += prev * curr;
                    prev = curr;
                }
            }
        } 
        return ans;
    }
};