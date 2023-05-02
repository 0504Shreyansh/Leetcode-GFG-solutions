class Solution {
public:
    bool isPalindrome(string &s, int i) {
        int N = s.size();
        if(i >= N/2) return true;
        if(s[i] != s[N-i-1]) return false;
        return isPalindrome(s, i+1);
    }

    int solve(int i, string &s) {
        int N = s.size();
        if(i >= N) return 0;
        int miniPartition = N;
        string tmp;
        for(int j = i; j < N; j++) {
            tmp += s[j];
            if(isPalindrome(tmp, 0)) {
                int curPartition = 1 + solve(j+1, s);
                miniPartition = min(miniPartition, curPartition);
            }
        }
        return miniPartition;
    }

    int minCut(string s) {
        // return solve(0, s) - 1;
        int N = s.size();
        vector<int> dp(N+1);
        dp[N] = 0;
        for(int i = N-1; i >= 0; i--) {
            string tmp;
            int mCost = N;
            for(int j = i; j < N; j++) {
                tmp += s[j];
                if(isPalindrome(tmp, 0)) {
                    int cost = 1 + dp[j+1];
                    mCost = min(mCost, cost);
                }
                dp[i] = mCost;
            }
        }
        return dp[0]-1;
    }
};