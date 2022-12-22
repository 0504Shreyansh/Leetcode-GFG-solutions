//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    /*Concept->
    arr    -> [6, -1, -3, 4, -2, 2, 4, 6, -12, -7]
    preSum -> [6, 5, 2, 6, 4, 6, 10, 16, 4, -3]
    subarr1->[-1, -3, 4] -> starts from i=1 to 3 (6 at index 0 and 3 in presSum)
    subarr2->[-2, 2] -> starts from i=4 to 5 (6 at index 3 and 5 in presSum)
    subarr3->[2, 4, 6, -12] -> starts from i=5 to 8 (4 at index 4 and 8 in presSum)
    subarr4->[-1, -3, 4, -2, 2] -> starts from i=1 to 5 (6 at index 0 and 5 in presSum)
    Summary -> 
    Map mei preSum store kro and contribution lelo and zeroes ko alag se handle kro*/
    long long int findSubarray(vector<long long int> &arr, int n ) {
        unordered_map<long long int,long long int> mp;
        long long int sum = 0, ans = 0;
        for(auto i:arr) {
            sum += i;
            mp[sum]++;
        }
        
        for(auto i:mp) {
            long long int val = i.second;
            if(i.first==0) ans += i.second;
            ans += (val*(val-1))/2;
            // cout<<i.first<<" "<<ans<<endl;
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
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends