class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n);
        for(auto edge : edges)
            inDegree[edge[1]]++;
        vector<int> answer;
        for(int i = 0; i < n; i++)
            if(inDegree[i] == 0)
                answer.push_back(i);
        return answer;
    }
};