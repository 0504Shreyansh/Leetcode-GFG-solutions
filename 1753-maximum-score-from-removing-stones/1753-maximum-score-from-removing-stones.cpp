class Solution {
/*Concept->
1. Just get the two largest vals and perform the operation till u have only one val left.
2. To implement this, use a priority queue.
*/
public:
    int maximumScore(int a, int b, int c) {
        
        priority_queue<int> pq;
        pq.push(a); pq.push(b); pq.push(c);
        int ans = 0;
        
        while(pq.size()) {
            if(pq.size()==1) break;
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            x--; y--; ans++;
            if(x) pq.push(x);
            if(y) pq.push(y);
        }
        
        return ans;
    }
};