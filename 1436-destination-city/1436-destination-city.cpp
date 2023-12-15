class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, int> indegree;
        for (auto &city : paths) {
            indegree[city[0]]++;
        }
        for (auto &city : paths) {
            if (indegree[city[1]] == 0) {
                return city[1];
            }
        }
        return "";
    }
};