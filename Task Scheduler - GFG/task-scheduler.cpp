//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        unordered_map<int,int> mp;
        for(auto &it : tasks) { 
            mp[it]++;   
        }
        priority_queue<int> pq;
        queue<pair<int,int>> q;
        for(auto &it : mp) {
            pq.push(it.second);
        }
        int time = 0;
        while(pq.size() || q.size()) {
            time++;
            if(pq.size()) {
                int top = pq.top();
                pq.pop();
                if(top - 1 > 0) q.push({top - 1, time + K});
            }
            if(q.size() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends