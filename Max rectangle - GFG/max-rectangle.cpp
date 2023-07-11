//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    vector<int> pSmaller(int arr[], int n) {
        stack<int> st;
        vector<int> res(n);
        for(int i = 0; i < n; i++) {
            while(st.size() && arr[st.top()] >= arr[i]) st.pop();
            res[i] = (st.size()) ? st.top() : -1;
            st.push(i);
        }
        return res;
    }
    vector<int> nSmaller(int arr[], int n) {
        stack<int> st;
        vector<int> res(n);
        for(int i = n - 1; i >= 0; i--) {
            while(st.size() && arr[st.top()] >= arr[i]) st.pop();
            res[i] = (st.size()) ? st.top() : n;
            st.push(i);
        }
        return res;
    }
    int maxArea(int arr[], int n) {
        vector<int> ps = pSmaller(arr, n);
        vector<int> ns = nSmaller(arr, n);
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            int width = ns[i] - ps[i] - 1;
            int height = arr[i];
            maxi = max(maxi, height * width);
        }
        return maxi;
    }

    int maxArea(int M[MAX][MAX], int n, int m) {
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int area = maxArea(M[i], m);
            ans = max(ans, area);
            for(int j = 0; j < m && i+1 < n; j++) if(M[i + 1][j]) M[i + 1][j] += M[i][j];
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends