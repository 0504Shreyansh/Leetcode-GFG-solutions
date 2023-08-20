//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool findPair(int arr[], int n, int size){
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        int low = i + 1, high = n  -1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (arr[mid] - arr[i] == size) return 1;
            if (arr[mid] - arr[i] < size) {
                low = mid + 1;   
            } else {
                high = mid - 1;
            }
        }
    }
    return 0;
}