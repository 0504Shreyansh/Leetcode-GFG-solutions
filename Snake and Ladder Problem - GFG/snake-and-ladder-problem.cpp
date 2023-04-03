//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        
        vector<int> adj[31];
        for(int i = 1; i <= 30; i++) {
            for(int j = i+1; j <= min(i+6, 30); j++) {
                adj[i].push_back(j);
            }
        }    
    
        map<int,int> mp;
        for(int i = 0; i < 2*N; i+=2)
            mp[arr[i]] = arr[i+1];
            
        // for(int i = 0; i <= 30; i++) {
        //     cout << i << "->";
        //     for(auto j : adj[i]) cout<<j<<" "; cout<<endl;
        // }
        
        
        // for(auto i : mp) {
        //     cout<<i.first<<' '<<i.second<<endl;
        // }
    
        queue<int> Q({1});
        vector<int> vis(31, 0);
        vis[1] = 1;
        int steps = 0;
    
        while(Q.size()) {
            int size = Q.size();
            while(size--) {
                int curPos = Q.front();
                // cout<<curPos<<' ';
                Q.pop();
                if(curPos == 30) {
                    return steps;
                }
                // cout<<"MP : "<<mp[curPos]<<' ';
                
                for(auto neighbour : adj[curPos]) {
                    if(!vis[neighbour]) {
                        vis[neighbour] = 1;
                        Q.push(neighbour);
                        if(mp.find(neighbour) != mp.end() && !vis[mp[neighbour]]) {
                            vis[mp[neighbour]] = 1;
                            Q.push(mp[neighbour]);
                            // cout<<"PUSHED : "<<mp[neighbour]<<endl;
                        }
                    }
                }
                
            }
            steps++;
            // cout<<endl;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends