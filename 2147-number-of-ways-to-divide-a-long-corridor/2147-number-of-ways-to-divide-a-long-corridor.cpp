class Solution {
public:
    int numberOfWays(string corridor) {
        
        int cnt = count(corridor.begin(),corridor.end(),'S');
        if(cnt==0 || cnt & 1) return 0;
        
        long long res = 1;
        int s = 0, p = 0;
        
        for (auto c : corridor) {
            if (c=='S') s++;
            if (s==2 && c=='P') p++;
            if (s > 2) {
                res = (res * (p + 1)) % 1000000007;
                p = 0;
                s = 1;
            }
        }
        return res;
    }
};