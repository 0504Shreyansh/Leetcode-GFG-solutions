//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &A, vector<int> &B) {
        sort(begin(A), end(A));
        sort(begin(B), end(B));
        int i = n - 1, j = n - 1;
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({A.back() + B.back(), {n - 1, n - 1}});
        vector<int> ans;
        set<pair<int, int>> visit;
        visit.insert({i, j});
        while (k--) {
            auto C = pq.top();
            pq.pop();
            int sum = C.first;
            int i = C.second.first, j = C.second.second;
            ans.push_back(sum);
            if (i - 1 >= 0 && !visit.count({i - 1, j})) {
                visit.insert({i - 1, j});
                pq.push({A[i - 1] + B[j], {i - 1, j}});
            }
            if (j - 1 >= 0 && !visit.count({i, j - 1})) {
                visit.insert({i, j - 1});
                pq.push({A[i] + B[j - 1], {i, j - 1}});
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends