//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &a) {
        stack<int> st;
        for (auto &it : a) {
            if (st.empty() || it > 0) {
                st.push(it);
            } else if (st.top() < 0 && it < 0) {
                st.push(it);
            } else {
                while (st.size() && st.top() > 0 && it < 0 && st.top() < abs(it)) {
                    st.pop();
                }
                if (st.empty()) {
                    st.push(it);
                } else if (st.top() < 0) {
                    st.push(it);
                } else if (st.top() == abs(it) && it < 0) {
                    st.pop();
                }
            }
        }   
        vector<int> res;
        while (st.size()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(begin(res),end(res));
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends