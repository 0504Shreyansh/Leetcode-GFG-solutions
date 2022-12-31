class Solution {
/*Concept -> 1. Create preXor rowise first
Ex - [[1, 2, 3],[4, 5, 6],[7, 8, 9]]
preXor -> [[1,1^2,1^2^3],
           [4,4^5,4^5^6],
           [7,7^8,7^8^9]]
2. Then create preXor col wise
preXor -> [[1,1^2,1^2^3],
           [1^4,1^2^4^5,1^2^3^4^5^6],
           [1^4^7,1^2^4^5^7^8,1^2^3^4^5^6^7^8^9]]
3. Push all values in a priority queue, return the kth largest.
*/
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size(), m = matrix[0].size();
        priority_queue<int> pq;
        vector<vector<int>> v(n, vector<int> (m, 0));
        
        for(int i=0;i<n;i++) {
            v[i][0] = matrix[i][0];
            for(int j=1;j<m;j++) {
                v[i][j] = v[i][j-1]^matrix[i][j];
            }
        }
        // for(auto i:v) {
        //     for(auto j:i) cout<<j<<" "; cout<<endl;
        // }
        
        for(int i=1;i<n;i++) {
            for(int j=0;j<m;j++) {
                v[i][j] ^= v[i-1][j];
            }
        }
        
        for(auto i:v) {
            for(auto j:i)
                pq.push(j);
        }
        // for(auto i:v) {
        //     for(auto j:i) cout<<j<<" "; cout<<endl;
        // }
        while(--k) {
            pq.pop();
        }
        
        return pq.top();
    }
};