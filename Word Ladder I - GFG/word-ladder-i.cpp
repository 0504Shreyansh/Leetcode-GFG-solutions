//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string start, string target, vector<string>& wordList) {
        
        int n = wordList.size();
        unordered_map<string,vector<string>> adj;
        unordered_map<string,bool> vis;
    
        //Create adjList for targetWord
        for(int i=0;i<n;i++) {
            string s = wordList[i];
            int diff = 0, m = s.size();
            for(int k=0;k<m;k++) {
                diff += (s[k]!=start[k]);
            }
            if(diff==1) {
                adj[s].push_back(start);
                adj[start].push_back(s);
            }
        }
        //Create adjList for the wordList
        for(int i=0;i<n-1;i++) {
            string s = wordList[i];
            for(int j=i+1;j<n;j++) {
                string ss = wordList[j];
                int diff = 0, m = s.size();
                for(int k=0;k<m;k++) {
                    diff += (s[k]!=ss[k]);
                }
                if(diff==1) {
                    adj[s].push_back(ss);
                    adj[ss].push_back(s);
                }
            }
        }
    
        // for(auto i: adj) {
        //     cout<<i.first<<"->";
        //     for(auto j: i.second) cout<<j<<" ";
        //     cout<<endl;
        // }
        
        queue<string> q;
        q.push(start);
        vis[start] = 1;
        int ans = 0;
        while(q.size()) {
            int size = q.size();
            ans++;
            for(int i=0;i<size;i++) {
                string s = q.front();
                q.pop();
                // cout<<s<<' ';
                if(s==target) return ans;
                for(auto e: adj[s]) {
                    if(!vis[e]) {
                        vis[e] = 1;
                        q.push(e);
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends