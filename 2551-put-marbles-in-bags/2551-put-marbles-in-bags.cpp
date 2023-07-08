class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        // w1, w2 ... w(n-1), w(n)
        // Possible partitions   
        // -- > w1 + w(i) + w(i+1) + w(j) + w(j+1) ... w(n)
        // adjacents are included where first and last always included
        // it can be concluded that its max((k-1)adjSums) - min((k-1)adjSums)
        int n = weights.size();
        vector<long long> marbles;
        for(int i = 1; i < n; i++) {
            marbles.push_back(weights[i] + weights[i - 1]);
        }
        sort(begin(marbles),end(marbles));
        long long best = 0;
        int m = marbles.size();
        for(int i = 0; i < k - 1; i++) {
            best += marbles[m - 1 - i];
            best -= marbles[i];
        }
        return best;
    }
};