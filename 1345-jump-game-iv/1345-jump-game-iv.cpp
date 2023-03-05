class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size(), steps = 0;
        map<int,vector<int>> indexes;

        vector<int> vis(n, 0);
        vis[0] = 1;
        for(int i = 0; i < n; i++) 
            indexes[arr[i]].push_back(i);
        queue<int> q({0});
        while(q.size()) {
            int x = q.size();
            while(x--) {
                int index = q.front();
                q.pop();
                if(index==n-1)
                    return steps;
                if(index-1>=0 && !vis[index-1])
                    vis[index-1]=1, q.push(index-1);
                if(index+1<n && !vis[index+1])
                    vis[index+1]=1, q.push(index+1);
                for(auto &x : indexes[arr[index]]) 
                    if(!vis[x])
                        vis[x]=1, q.push(x);  
                indexes[arr[index]].clear();
            }
            steps++; 
        }
        return steps;
    }
};