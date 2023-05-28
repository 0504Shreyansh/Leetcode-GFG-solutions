//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class SGTree {
    vector<int> sgt;
    public:
    SGTree(int n) {
        sgt.resize(4 * n);
    }
    void build(int index, int low, int high, int* arr) {
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
    vector<int> specialXor(int N, int Q, int a[], vector<int> query[])
    {
        int XOR = 0;
        for(int i = 0; i < N; i++) XOR ^= a[i];
        SGTree sg(N);
        sg.build(0, 0, N - 1, a);
        vector<int> ans(Q);
        for(int i = 0; i < Q; i++) {
            ans[i] = XOR ^ sg.query(0, query[i][0]-1, query[i][1]-1, 0, N - 1);
        }
        return ans;
    }
}; 

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, Q;
        cin>>N>>Q;
        int a[N];
        for(int i = 0;i < N;i++)
            cin>>a[i];
        int l, r;
        vector<int> query[Q];
        for(int i = 0;i < Q;i++){
            cin>>l>>r;
            query[i].push_back(l);
            query[i].push_back(r);
        }
        
        Solution ob;
        vector<int> ans = ob.specialXor(N, Q, a, query);
        for(int u: ans)
            cout<<u<<"\n";
    }
    return 0;
}
// } Driver Code Ends