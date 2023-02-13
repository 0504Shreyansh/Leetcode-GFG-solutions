class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        vector<int> visited(10000);
        for(auto e: deadends)
            visited[stoi(e)] = 1;
        if(visited[0])
            return -1;
        visited[0] = 1;
        queue<string> q;
        q.push("0000");
        
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
                    if(org=='0')
                    {
                        cur[k] = '9';
                        if(!visited[stoi(cur)]) {q.push(cur); visited[stoi(cur)]++;}
                        cur[k] = '1';
                        if(!visited[stoi(cur)]) {q.push(cur); visited[stoi(cur)]++;}
                    }
                    else if(org=='9') 
                    {
                        cur[k] = '0';
                        if(!visited[stoi(cur)]) {q.push(cur); visited[stoi(cur)]++;}
                        cur[k] = '8';
                        if(!visited[stoi(cur)]) {q.push(cur); visited[stoi(cur)]++;}
                    }
                    else
                    {
                        cur[k] = org - 1;
                        if(!visited[stoi(cur)]) {q.push(cur); visited[stoi(cur)]++;}
                        cur[k] = org + 1;
                        if(!visited[stoi(cur)]) {q.push(cur); visited[stoi(cur)]++;}
                    }
                    cur[k] = org;
                }
            }
            steps++;
            // cout<<endl;
        }        
        return -1;
    }
};