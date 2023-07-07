class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;
        if(k == 0) {
            for(int i = 0; i < n; i++) {
                int j = i;
                while(j + 1 < n && s[j + 1] == s[i]) j++;
                ans = max(ans, j - i + 1);
                i = j;
            }
            return ans;
        }
        // change to each possible chars
        for(char ch = 'A'; ch <= 'Z'; ++ch) {
            int i = 0;
            deque<int> dq;
            for(int j = 0; j < n; ++j) {
                if(s[j] != ch) {
                    while(dq.size() == k && i <= j) {
                        if(dq.front() == i++) dq.pop_front();
                    }
                    dq.push_back(j);    
                }
                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};