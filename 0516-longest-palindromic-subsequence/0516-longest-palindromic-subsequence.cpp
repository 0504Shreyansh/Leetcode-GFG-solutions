class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        string r = s;
        reverse(begin(r),end(r));
        int N = s.size();
        
        vector<int> prev(N+1, 0), cur(N+1, 0);
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (s[i-1] == r[j-1])
                    cur[j] = 1 + prev[j-1];
                else 
                    cur[j] = max(prev[j], cur[j-1]);
            } 
            prev = cur;
        }
        
        return prev[N];
        
    }
};