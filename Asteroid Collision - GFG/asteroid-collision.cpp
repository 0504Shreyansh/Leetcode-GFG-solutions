//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &a) {
        stack<int> st;
        for(auto &it : a) {
            if(it > 0) {
                st.push(it);
            }
            else if(it == 0) {
                continue;
            }
            else {
                if(st.empty() || st.top() < 0) {
                    st.push(it);
                }
                else if(st.top() == abs(it)) {
                    st.pop();
                }
                else if(st.top() > abs(it)) {
                    continue;
                }
                else {
                    bool f = 0;
                    while(!st.empty() && st.top() > 0 && st.top() <= abs(it)) {
                        if(st.top() == abs(it)) {
                            st.pop(); f = 1;
                            break;
                        } else st.pop();
                    }
                    if(st.size() && st.top() > abs(it)) continue;
                    if(!f)
                    st.push(it);
                }
            }
        }
        vector<int> res(st.size());
        while(!st.empty()) {
            res[st.size() - 1] = st.top();
            st.pop();
        }
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