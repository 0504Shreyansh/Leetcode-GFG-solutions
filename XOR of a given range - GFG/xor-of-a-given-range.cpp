//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class SGTree {
    vector<int> sgt;
    public:
    SGTree(int n) {
        sgt.resize(4 * n);
    }
    void build(int index, int low, int high, vector<int>& arr) {
        if(low == high) {  // base case reached the last node
            sgt[index] = arr[low];
            return ;
        }
        int mid = (low + high) / 2;
        build(2 * index + 1, low, mid, arr);  // build left
        build(2 * index + 2, mid + 1, high, arr);  // build right
        sgt[index] = (sgt[2 * index + 1] ^ sgt[2 * index + 2]);
    }
    int query(int index, int l, int r, int low, int high) {
        if(l > high || low > r) return 0;  // out of range
        if(l <= low && high <= r) return sgt[index];  // found inside the range
        int mid = (low + high) / 2;
        int left = query(2 * index + 1, l, r, low, mid);
        int right = query(2 * index + 2, l, r, mid + 1, high);
        return (left ^ right);
    }   
    void update(int index, int i, int val, int low, int high) {
        if(low == high) {    // found the index 
            sgt[index] = val;
            return ;
        }
        int mid = (low + high) / 2;
        if(i <= mid) update(2 * index + 1, i, val, low, mid);
        else update(2 * index + 2, i, val, mid + 1, high);
        sgt[index] = (sgt[2 * index + 1] ^ sgt[2 * index + 2]);
    }
};

class Solution{
    public:
    int getXor(vector<int>&nums, int a, int b){
        int n = nums.size();
        SGTree sg(n);
        sg.build(0, 0, n - 1, nums);
        return sg.query(0, a, b, 0, n - 1);
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