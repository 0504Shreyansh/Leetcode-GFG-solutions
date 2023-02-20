//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    
	    vector<pair<int,int>> dir = {{1,2}, {-1,2}, {1,-2}, {-1,-2}, {2,1}, {-2,1}, {2,-1}, {-2,-1}};
	    int steps = 0;
	    queue<pair<int,int>> q({{KnightPos[0], KnightPos[1]}});
	    vector<vector<int>> vis(N+1, vector<int> (N+1));
	    for(int i = 0; i < N+1; i++) vis[0][i] = vis[i][0] = 1;
	    vis[KnightPos[0]][KnightPos[1]] = 1;
	    
	    while(q.size()) {
	        int n = q.size();
	        for(int i = 0; i < n; i++) {
	            auto cur = q.front();
	            q.pop();
	            int curRow = cur.first, curCol = cur.second;
	           // cout<<curRow<<' '<<curCol<<endl;
	            if(curRow==TargetPos[0] && curCol==TargetPos[1])
	                return steps;
	            for(int k = 0; k < 8; k++) {
	                int newRow = curRow + dir[k].first, newCol = curCol + dir[k].second;
	                if(newRow>=0 & newCol>=0 & newRow<N+1 && newCol<N+1 && !vis[newRow][newCol]) {
	                    vis[newRow][newCol] = 1;
	                    q.push({newRow, newCol});
	                }
	            }
	        }
	        steps++;
	    }
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends