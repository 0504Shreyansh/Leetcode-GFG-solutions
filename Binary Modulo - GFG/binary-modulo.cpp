//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int binpow(long long a, long long b, long long m) {
        long long ans = 1;
        while (b) {
            if (b & 1)
                ans = (ans * a) % m;
            a = (a * a) % m;
            b >>= 1;
        }
        return ans % m;
    }
    
    int modulo(string s, int m) {
        int N = s.size();
        int ans = 0;
        for (int i = N - 1; i >= 0; --i) {
            if (s[i] == '1') 
                ans = (ans + binpow(2, N - 1 - i, m)) % m;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends