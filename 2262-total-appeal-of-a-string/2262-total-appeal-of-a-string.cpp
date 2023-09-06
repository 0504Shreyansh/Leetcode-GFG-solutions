class Solution {
private:
    long long contribution(char c, string &s) {
        long long cnt = 0;
        long long contri = 0;
        for (auto &it : s) {
            if (it == c) {
                contri += (cnt * (cnt + 1)) / 2;
                cnt = 0;
            } else {
                cnt++; 
            }
        }
        contri += (cnt * (cnt + 1)) / 2;
        return contri;
    }
public:
    long long appealSum(string s) {
        long long n = s.size();
        long long res = (n * (n + 1)) / 2;
        map<char, int> freq;
        for (auto &it :  s) freq[it]++;
        res *= (int)freq.size();
        for (auto &it : freq) {
            res -= contribution(it.first, s);
        }
        return res;
    }
};