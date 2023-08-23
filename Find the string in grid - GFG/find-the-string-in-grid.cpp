//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<pair<int, int>> dir = {{-1, -1}, {-1, 0}, 
	    {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    bool dfs(int i, int j, int& k, vector<vector<char>>& grid, int index, string& word) {
        // cout << i << ' ' << j << endl;
        if (index >= word.size()) {
            return true;
        }
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || (index < word.size() && grid[i][j] != word[index])) {
            return false;
        }
        return dfs(i + dir[k].first, j + dir[k].second, k, grid, index + 1, word);
	}
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    int n = grid.size(), m = grid[0].size();
	    vector<vector<int>> ans;
	    for (int i = 0; i < n; i++) {
	        for (int j = 0; j < m; j++) {
	            bool f = false;
	            for (int k = 0; k < 8; k++) {
	                if (dfs(i, j, k, grid, 0, word)) {
	                    f = true;
	                    break;
	                }
	            }
	            if (f) {
	                ans.push_back({i, j});
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
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends