class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        
        int n = s.size();
        string ans(n, '9');
        
        queue<string> Q({s});
        unordered_map<string,int> vis;
        vis[s]++;
        
        while(Q.size()) {
            int sz = Q.size();
            for(int i = 0; i < sz; i++) {
                string cur = Q.front(), p = Q.front();
                Q.pop();
                
                //Better answer found
                if(cur < ans) 
                    ans = cur;
                
                //New string after rotating by b digits
                string r = cur.substr(b, n-b) + cur.substr(0, b);
                
                //New string on adding a at all the odd indices
                for(int i = 1; i < n; i += 2) 
                    p[i] = (((p[i]-'0') + a) % 10) + '0';
        
                if(!vis[p]) {Q.push(p), vis[p]++;}
                if(!vis[r]) {Q.push(r), vis[r]++;}
            }
        }
        return ans;
    }
};