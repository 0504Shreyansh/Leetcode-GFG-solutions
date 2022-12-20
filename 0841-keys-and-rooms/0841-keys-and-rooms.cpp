class Solution {
public:
    bool allTrue(vector<bool> v) {
        bool f = true;
        for(auto i:v) f&=i;
        return f;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        // map<int,bool> mp;
        vector<bool> v(n,false);
        queue<int> q;
        v[0] = true;
        for(int k=0;k<rooms[0].size();k++) {
            v[rooms[0][k]] = true;
            q.push(rooms[0][k]);
        }
        // while(q.size()) {
        //     cout << q.front()<<" ";
        //     q.pop();
        // }cout<<endl;
        // for(auto i:v) cout<<i<<" "; cout<<endl;
        while(q.size()) {
            int i = q.front(); q.pop();
            // v[i] = true;
            // cout<<i<<" ";
            for(auto j:rooms[i]) {
                if(!v[j]) {
                    v[j] = true;
                    q.push(j);
                }
            }
            if(allTrue(v)) return true;  
        }
        
        // for(auto i:v) cout<<i<<" "; cout<<endl;
        return false;
    }
};