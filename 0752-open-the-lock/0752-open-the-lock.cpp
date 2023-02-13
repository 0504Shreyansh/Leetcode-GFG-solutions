class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        vector<int> visited(10000);
        for(auto e: deadends)
            visited[stoi(e)] = 1;
        if(visited[0])
            return -1;
        visited[0] = 1;
        
        queue<string> q({"0000"});
        int steps = 0;
        
        while(q.size()) 
        {
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                string cur = q.front();
                q.pop();
                // cout<<cur<<' ';
                if(cur==target) 
                    return steps;
                for(int k = 0; k < 4; k++)
                {
                    char org = cur[k];
                    //Change to the next by handling char = '9'
                    cur[k] = (org == '9') ? '0' : org + 1;
                    if(!visited[stoi(cur)]) {
                        q.push(cur);
                        visited[stoi(cur)] = 1;
                    }
                    //Change to the prev by handling char = '0'
                    cur[k] = (org == '0') ? '9' : org - 1;
                    if(!visited[stoi(cur)]) {
                        q.push(cur);
                        visited[stoi(cur)] = 1;
                    }
                    cur[k] = org;
                }
            }
            steps++;
        }        
        return -1;
    }
};