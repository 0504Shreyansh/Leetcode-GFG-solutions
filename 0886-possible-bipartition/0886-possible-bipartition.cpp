class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<int> graph[n+1];
        for(auto it : dislikes) {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        
        vector<int> color(n+1, -1);
        
        for (int node = 1; node <= n; node++)
        {
            if (color[node]==-1)
            {
                queue<int> q({node});
                color[node] = 0;
                while (q.size()) 
                {
                    int size = q.size();
                    while (size--)
                    {
                        int curNode = q.front();
                        q.pop();
                        int colour = color[curNode];
                        for (auto neighbour : graph[curNode]) 
                        {
                            if (color[neighbour] == -1) {
                                color[neighbour] = !colour;
                                q.push(neighbour);
                            }
                            else if (color[neighbour] == colour)
                                return false;
                        }
                    }
                }
            }
        }
        
        return true;
        
    }
};