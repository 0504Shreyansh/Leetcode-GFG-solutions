class Solution {
public:
    // int store[10][5001];
    int solverrr(int i, vector<vector<int>>& positions, int n, vector<vector<int>>& store) {
        if(n==1) {
            return 1;
        }

        if(store[i][n] != -1) {
            return store[i][n];
        }
        
        int cur = 0;
        for(auto pos : positions[i]) {
            cur = (cur + solverrr(pos, positions, n-1, store)) % 1000000007;    
        }
        
        return store[i][n] = cur % 1000000007;
    }

    int knightDialer(int n) {
        
        // Store the possible positions of each number in the dial pad
        vector<vector<int>> positions = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};

        // Create a dp array of 10*n dimension
        vector<vector<int>> store(10, vector<int> (n+1, -1));

        // Discover and count all the possiblilties 
        int res = 0;
        for(int i = 0; i < 10; i++) {
            res = (res + solverrr(i, positions, n, store)) % 1000000007;
        }
        
        return res;
    }
};