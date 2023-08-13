//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class SGTree {
public:
    vector<int> sg;
    SGTree(int n) {
        sg.resize(4 * n);
    }
    void build(int low, int high, int index, vector<int>& A) {
        if (low == high) {
            sg[index] = A[low];
            return ;
        }
        int mid = (low + high) / 2;
        build(low, mid, 2 * index + 1, A);
        build(mid + 1, high, 2 * index + 2, A);
        sg[index] = (sg[2 * index + 1] ^ sg[2 * index + 2]);
    }
    int query(int low, int high, int l, int r, int index, vector<int>& A) {
        if (l <= low && high <= r) {
            return sg[index];
        }
        if (high < l || r < low) {
            return 0;
        }
        int mid = (low + high) / 2;
        return (query(low, mid, l, r, 2 * index + 1, A) ^ query(mid + 1, high, l, r, 2 * index + 2, A));
    }
};

class Solution{
    public:
    int getXor(vector<int>&A, int a, int b){
        int n = A.size();
        SGTree obj(n);
        obj.build(0, n - 1, 0, A);
        return obj.query(0, n - 1, a, b, 0, A);
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--){
        int n, a, b;
        cin >> n >> a >> b;
        vector<int>nums(n);
        for(int i = 0; i < n; i++)cin >> nums[i];
        if(a > b)swap(a, b);
        Solution obj;
        int ans = obj.getXor(nums, a, b);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends