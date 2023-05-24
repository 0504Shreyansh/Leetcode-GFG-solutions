#define mod 1000000007
class Solution {
public:
    int countVowelPermutation(int n) {
        vector<int> cur(5, -1), prev(5, -1);;
        for(int i = 0; i < 5; i++) {
            prev[i] = 1;
        }
        for(int i = 2; i <= n; i++) {
            cur[0] = (prev[1]) % mod;  //a
            cur[1] = (prev[0] + prev[2]) % mod;  //e
            cur[2] = ((((prev[0] + prev[1]) % mod) + prev[3]) % mod + prev[4]) % mod;   //i
            cur[3] = (prev[2] + prev[4]) % mod;  //o
            cur[4] = (prev[0]) % mod;  //u
            prev = cur;
        }
        int ans = 0;
        // count all vowels
        for(int i = 0; i < 5; i++) 
            ans = (ans + prev[i]) % mod;
        return ans;
    }
};