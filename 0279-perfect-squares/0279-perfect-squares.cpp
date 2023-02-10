class Solution {
public:
    int numSquares(int n) {
        
        vector<int> visited(1e4), perf;
        queue<int> q;
        q.push(n);
        int count = 1, i = 1;
        
        while(i*i<=n) 
            perf.push_back(i*i), i++;
        
        while (q.size()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int curr = q.front();
                q.pop();
                for (int k = 0; k < perf.size(); k++) {
                    int val = 0;
                    if(curr > perf[k]) {
                        q.push(curr-perf[k]);
                        visited[perf[k]] = 1;
                    }
                    else if(curr==perf[k])
                        return count;
                    else break;
                }
            } 
            count++;
        }
        
        return 3;
    }
};