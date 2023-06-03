class Solution {
public:
    int minDays(int n) {
        int ans = 0;
        set<int> vis;
        queue<int> Q;
        Q.push(n);
        while(!Q.empty()) {
            int size = Q.size();
            while(size--) {                
                int num = Q.front();
                Q.pop();
                if(num <= 0) {
                    return ans;
                } 
                if(!vis.count(num - 1)) {
                    vis.insert(num - 1);
                    Q.push(num - 1);
                }
                if(num % 2 == 0 && !vis.count(num / 2)) {
                    vis.insert(num / 2);
                    Q.push(num / 2);
                }
                if(num % 3 == 0 && !vis.count(num / 3)) {
                    vis.insert(num / 3);
                    Q.push(num / 3);
                }
            }
            ans++;
        }
        return -1;
    }
};