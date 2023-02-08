//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        queue<int> q;
        int steps = 0;
        q.push(start);
        vector<int> vis(1e5);
        
        while (q.size()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                int curr = q.front();
                q.pop();
                if(curr==end)
                    return steps;
                for (int k = 0; k < arr.size(); k++) {
                    long long val = (curr * arr[k]) % 100000;
                    if (!vis[val]) {
                        vis[val] = 1;
                        q.push(val);
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends