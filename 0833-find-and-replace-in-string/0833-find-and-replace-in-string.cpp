class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        map<int, int> m;
        for (int i = 0; i < indices.size(); i++) {
            if (m.find(indices[i]) == m.end() && s.substr(indices[i], sources[i].size()) == sources[i])
                m[indices[i]] = i;
        }
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (m.find(i) != m.end()) {
                int index = m[i];
                if (s.substr(i, sources[index].size()) == sources[index]) {
                    res += targets[index];
                    i += sources[index].size() - 1;
                } else {
                    res += s[i];
                }
            } else {
                res += s[i];
            }
        }
        return res;
    }
};