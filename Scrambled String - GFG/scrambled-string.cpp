//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    public:
    // Keeps a track of the visited strings, 
    // whether they are capable of generating string  
    unordered_map<string,bool> vis;
    bool solve(string s1, string s2) {
        // Base case => Both strings match -> return true
        if(s1 == s2) 
            return true;
            
        // Not possible to generate the string 
        if(s1.size() != s2.size()) 
            return false;
        
        string newString = s1 + "+" + s2;
        
        // Already known whether it will yield the other string
        // return the bool value stored in it.
        if(vis.find(newString) != vis.end())
            return vis[newString];
   
        bool res = false;
        int n = s1.size();
        for(int i = 1; i < n; i++) {
            // (gr)|((eat)) & ((eat))|(gr)
            bool swapped = solve(s1.substr(0, i), s2.substr(n-i, i)) 
                && solve(s1.substr(i, n-i), s2.substr(0, n-i));
            if(swapped) {
                res = true;
                break;
            }
            // (gr)|((eat)) & (gr)|((eat))
            bool notSwapped = solve(s1.substr(0, i), s2.substr(0, i)) 
                && solve(s1.substr(i, n-i), s2.substr(i, n-i));
            if(notSwapped) {
                res = true;
                break;
            }
        }
        
        // Store and return the boolean value
        return vis[newString] = res;
    }
    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends