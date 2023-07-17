//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
private:
    vector<int> prevSmaller(long long arr[], int n) {
        vector<int> p(n, -1);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(st.size() && arr[st.top()] >= arr[i]) st.pop();
            if(st.size()) p[i] = st.top();
            st.push(i);
        }
        return p;
    }
    vector<int> nextSmaller(long long arr[], int n) {
        vector<int> p(n, n);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
            while(st.size() && arr[st.top()] >= arr[i]) st.pop();
            if(st.size()) p[i] = st.top();
            st.push(i);
        }
        return p;
    }
    
public:
    long long getMaxArea(long long arr[], int n)
    {
        long long ans = 0;
        vector<int> prev = prevSmaller(arr, n);
        vector<int> next = nextSmaller(arr, n);
        for(int i = 0; i < n; i++) {
            long long height = arr[i];
            long long width = next[i] - prev[i] - 1;
            long long curArea = height * width;
            ans = max(ans, curArea);
        } 
        return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends