class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char, int> m1, m2;
        for (auto &it : word1) m1[it]++;
        for (auto &it : word2) m2[it]++;
        vector<int> p, q;
        for (auto &it : m1) p.push_back(it.second);
        for (auto &it : m2) q.push_back(it.second);
        sort(begin(p), end(p));
        sort(begin(q), end(q));
        if (p != q) return false;
        for (auto &it : m1) p.push_back(it.first);
        for (auto &it : m2) q.push_back(it.first);
        sort(begin(p), end(p));
        sort(begin(q), end(q));
        if (p != q) return false;
        return true;
    }
};