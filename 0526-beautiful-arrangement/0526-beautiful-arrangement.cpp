class Solution {
public:
    int size = 16;
    vector<int> taken;
    int solve(int i, int n) {

        if(i==n) {
            return 1;
        }

        int cur = 0;
        for(int k = 1; k <= n; k++) {
            if((k%(i+1)==0 || (i+1)%k==0) && !taken[k]) {
                taken[k]++;
                cur += solve(i+1, n);
                taken[k]--;
            }
        }
        return cur;
    }

    int countArrangement(int n) {
        taken.resize(16);
        return solve(0, n);
    }
};