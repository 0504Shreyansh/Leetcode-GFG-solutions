class Solution {
public:
    int minSteps(string s, string t) {
        int ans = 0, n = s.size();
        vector<int> freq(26);
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        for (int &f : freq) {
            ans += abs(f);
        }
        return ans / 2;
    }
};