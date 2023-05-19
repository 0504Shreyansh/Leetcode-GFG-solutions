#define ll long long
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<ll> Q;
        Q.push(-1);
        for(auto p : primes)
            Q.push(-p);
        unordered_set<ll> vis;
        while(!Q.empty()) {
            int val = -Q.top();
            Q.pop();
            if(vis.count(val)) 
                continue;
            vis.insert(val);
            if(--n == 0) 
                return val;
            for(auto p : primes)
                Q.push((ll)(-p) * val);
        }
        return -1;
    }
};