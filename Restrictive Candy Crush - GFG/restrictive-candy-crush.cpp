//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string Reduced_String(int k,string s){
        stack<pair<char, int>> st;
        for(int i = 0; i < s.size(); i++) {
            if(st.size() && st.top().second == k) st.pop();
            if(st.empty() || st.size() && st.top().first != s[i]) {
                st.push({s[i], 1});
            } else {
                int t = st.top().second;
                char prev = st.top().first;
                st.pop();
                st.push({prev, t + 1});
            }
        }
        while(st.size() && st.top().second==k) st.pop();
        string res;
        while(st.size()) {
            int t = st.top().second;
            while(t--)
                res += st.top().first;
            st.pop();
        }
        reverse(begin(res),end(res));
        return res;
    }


};

//{ Driver Code Starts.

int main() {
    
    
    int t;cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.Reduced_String(k,s)<<"\n";
        
    }
    
	return 0;
}
// } Driver Code Ends