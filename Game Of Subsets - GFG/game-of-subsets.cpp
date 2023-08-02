//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
private:
    const int mod = 1e9 + 7;
    int gcd(long long a, long long b) {
        return (a == 0) ? b : gcd(b % a, a);
    }
    long long solve(int i, long long product, vector<int>& A, map<int, int>& freq) {
        if (i >= A.size()) return (product != 1);
        long long notPick = solve(i + 1, product, A, freq);
        long long pick = 0;
        if (gcd(A[i], product) == 1) {
            pick = (freq[A[i]] * solve(i + 1, product * A[i], A, freq)) % mod;
        }
        return (pick + notPick) % mod;
    }
public:
    int goodSubsets(vector<int> &arr, int n){
        map<int, int> freq;
        for (auto &it : arr) {
            bool ok = 1;
            for (int j = 2; j * j <= it; j++) {
                if (it % (j * j) == 0) {
                    ok = 0;
                    break;
                }
            }
            if (ok) freq[it]++;
        }
        vector<int> A;
        for (auto &it : freq) {
            A.push_back(it.first);
        }
        int ans = max(1, freq[1] - 1) * solve(0, 1ll, A, freq);
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution ob;
        cout<<ob.goodSubsets(a, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends