//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    unordered_map<string,int> mp;
    bool solve(int i, string A, string cur) {
        if(i >= A.size()) {
            if(cur.size()==0)
            return true;
            else
            return false;
        }
            
        bool notConsider = solve(i+1, A, cur+A[i]);
        bool consider = false;
        cur += A[i];
        if(mp[cur]) {
            consider = solve(i+1, A, "");
        }
        
        return (consider || notConsider);
    }
    int wordBreak(string A, vector<string> &B) {
        for(auto b : B)
            mp[b]++;
        return solve(0, A, "");
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends