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
    long long power(long long a, long long b) {
        long long ans = 1ll;
        while (b) {
            if (b & 1) ans = (ans * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return ans;
    }
    long long solve(int i, long long product, vector<int>& A, map<int, int>& freq) {
        if (i >= A.size()) return (product != 1);
        long long res = solve(i + 1, product, A, freq);
        if (gcd(A[i], product) == 1) {
            res += (freq[A[i]] * solve(i + 1, product * A[i], A, freq)) % mod;
            res %= mod;
        }
        return res;
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
        // cout << freq[1] << endl;
        long long ans = (power(2, freq[1]) * solve(0, 1, A, freq)) % mod;
        return ans / (freq[1] + 1);
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