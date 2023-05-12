//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int>& A) {
        bool found = false;
        int ans = 0, cnt = 0;
        for(auto it : A) {
            if(it != 0) {
                cnt++;
            }
            else {
                found = true;
                if(cnt > 0) {
                    ans++;
                    cnt = 0;
                }
            }
        }
        if(cnt > 0) ans++;
        return (found) ? ans : -1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends