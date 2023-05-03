//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
    bool makePalindrome(int n, vector<string>& arr) {
        map<string,int> mp;
        for (int i = 0; i < n; i++) {
            string tmp = arr[i];
            reverse(begin(tmp),end(tmp));
            (mp.find(tmp) != mp.end()) ? mp.erase(tmp) : mp[arr[i]]++;
        }
        return (mp.size()==0 || isPalindrome((*mp.begin()).first));
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends