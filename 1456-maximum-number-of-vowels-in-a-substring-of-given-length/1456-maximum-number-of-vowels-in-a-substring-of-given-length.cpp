class Solution {
public:
    bool isVowel(char ch) {
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }
    int maxVowels(string s, int k) {
        int ans = 0;
        int n = s.size();
        int i = 0;
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            cnt += isVowel(s[j]);
            if(j - i + 1 == k) {
                ans = max(ans, cnt);
                cnt -= isVowel(s[i++]);
            } 
        }
        return ans;
    }
};