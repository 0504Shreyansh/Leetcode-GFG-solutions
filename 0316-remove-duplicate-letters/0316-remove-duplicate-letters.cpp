class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        vector<bool> used(26, false);
        vector<int> cnt(26, 0);
        for (auto c : s)
            cnt[c - 'a']++;
        for (auto c : s) {
            cnt[c - 'a']--;
            if (used[c - 'a'])
                continue;
            while (!st.empty() && st.top() > c && cnt[st.top()-'a'] > 0) {
                used[st.top()-'a'] = false;
                st.pop();
            }
            used[c - 'a'] = true;
            st.push(c);
        }
        string res(st.size(), '.');
        while (st.size()) {
            res[st.size() - 1] = st.top();
            st.pop();
        }
        return res;
    }
};