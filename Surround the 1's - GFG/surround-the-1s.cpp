//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dir = {{-1, 0}, {-1, -1}, {-1, 1}, {0, 1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 1) {
                    int c = 0;
                    for (auto &v : dir) {
                        int x = i + v[0], y = j + v[1];
                        if (x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] == 0) {
                            c++;
                        }
                    }
                    if (c > 0 && c % 2 == 0) ans++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends