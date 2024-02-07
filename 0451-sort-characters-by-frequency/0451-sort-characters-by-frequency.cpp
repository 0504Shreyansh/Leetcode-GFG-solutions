class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        for (auto &c : s) mp[c]++;
        priority_queue<tuple<int, char>> pq;
        for (auto &x : mp) pq.push(tuple(x.second, x.first));
        string ans;
        while (!pq.empty()) {
            tuple<int, char> a = pq.top();
            pq.pop();
            while (get<0>(a)--) ans += get<1>(a);
        }
        return ans;
    }
};