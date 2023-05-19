#define ll long long
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1) {
            return n;
        }
        --n;
        unordered_set<int> vis;
        vector<ll> primes = {2, 3, 5};
        priority_queue<ll> Q;
        for(auto p : primes)
            Q.push(-p);
        while(!Q.empty()) {
            ll val = -Q.top();
            Q.pop();
            if(vis.count(val))
                continue;
            if(--n == 0) {
                return val;
            }
            vis.insert(val);
            for(auto p : primes)
                Q.push(-p * val);
        }
        return -1;
    }
};