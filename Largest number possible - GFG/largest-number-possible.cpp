//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        if (N * 9 < S) return "-1";
        if (S == 0 && N == 1) {
            return "0";
        }
        if (S == 0) {
            return "-1";
        }
        string res;
        while (S) {
            if (S >= 9) {
                res += '9';
                S -= 9;
            } else {
                res += (S + '0');
                S = 0;
            }
        }
        while (res.size() != N) res += '0';
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends