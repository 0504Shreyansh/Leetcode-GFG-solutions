class Solution {
public:
    long long contribution(char ch, string s) {
        long long count = 0;
        long long c = 0;
        long long n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] != ch) {
                c++;
            } else {
                count += (c * (c + 1)) / 2;
                c = 0;
            }
        }   
        count += (c * (c + 1)) / 2;
        // cont. of 'ch' charcater = total - cont. with no 'ch' character
        return (n * (n + 1)) / 2 - count;
    }

    long long appealSum(string s) {
        long long res = 0;
        // cont. of each char
        for(char ch = 'a'; ch <= 'z'; ch++) {
            res += contribution(ch, s);
        }
        return res;
    }
};