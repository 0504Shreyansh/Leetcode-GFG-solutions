//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
vector<int> f(vector<int>ans, int m, int n){
        int c = 0, j = m;
        
        if(ans[j]==9)
        {
            ans[j]=0;
            c  = 1;
        }
        else ans[j]++;
        j--;
        
        while(c&& j>=0)
        {
            int res = ans[j]+c;
            ans[j] = (res)%10;
            c = res/10;
            j--;
        }
        if(c)ans.insert(ans.begin(), 1);
        if(n%2)
        {
            for(int i=m-1; i>=0;i--)
            ans.push_back(ans[i]);
        }
        else
        {
            for(int i=m; i>=0; i--)
            ans.push_back(ans[i]);
        }
        return ans;
    }
vector<int> generateNextPalindrome(int nums[], int n) {
    
    if(n==1 && nums[0]==9)
    return {1,1};
    vector<int>ans,v;
        int m=(n-1)/2,j=m;
    for(int i=0;i<=m;i++) ans.push_back(nums[i]);
    v=ans;
    bool c=false;
    if(n%2) j--;
    for(int i=j;i>=0;i--)
    {
        v.push_back(v[i]);
        if(c) continue;
        if(v.back()>nums[v.size()-1]) c=true;
        if(v.back()<nums[v.size()-1]) break;
    }
    if(!c) return f(ans,m,n);
    return v;
}
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends