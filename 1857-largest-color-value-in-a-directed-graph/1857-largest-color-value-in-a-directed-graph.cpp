class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> adj[n];
        vector<int> inDegree(n, 0);
        
        // Step 1 : Create graph and calculate inDegree
        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;   
        }
        
        // Step2 : Push all the nodes into queue whose inDegree is 0.
        // (Kahn's Algorithm)
        queue<int> Q;
        for(int i = 0; i < n; i++) {
            if(inDegree[i]==0) {
                Q.push(i);
            }
        }
        
        // Step 3 : Create a 2D dp to keep track of the nodes with color
        vector<vector<int>> dp(n+1, vector<int> (26, 0));
        int cnt = 0;
        int ans = -1;
        
        while(Q.size()) {
            int size = Q.size();
            cnt += size;
            for(int i = 0; i < size; i++) {
                int curNode = Q.front();
                Q.pop();
                
                // Increment the coutn of the current color
                dp[curNode][colors[curNode]-'a']++;
                // Update the answer
                ans = max(ans, dp[curNode][colors[curNode]-'a']);
                for(int neighbour : adj[curNode]) {
                    // Apply kahn's algo.
                    if(--inDegree[neighbour]==0) {
                        Q.push(neighbour);
                    }
                    // Check out for the maximum value of color 
                    for(int i = 0; i < 26; i++) {
                        dp[neighbour][i] = max(dp[neighbour][i], dp[curNode][i]);
                        ans = max(ans, dp[neighbour][i]);
                    }
                }
            }
        }
        
        // Edge case : Check if there is a cycle => No ans possible
        if(cnt != n) 
            return -1;
        
        return ans;
    }
};