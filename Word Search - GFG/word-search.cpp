//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<pair<int,int>> direction = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool dfs(int index, int i, int j, vector<vector<char>>& grid, string& word) {
        int n = grid.size();
        int m = grid[0].size();
        if(index == word.size()) {
            return true;
        }
        if(i< 0 || i >= n || j < 0 || j >= m || grid[i][j] != word[index]) {
            return false;
        }
        
        grid[i][j] = '#';
        bool ans = false;
        for(auto v : direction) {
            int X = i + v.first;
            int Y = j + v.second;
            if(dfs(index + 1, X, Y, grid, word)) {
                return true;
            }
        }
        
        grid[i][j] = word[index];
        return ans;
    }
    bool isWordExist(vector<vector<char>>& grid, string word) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(dfs(0, i, j, grid, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends