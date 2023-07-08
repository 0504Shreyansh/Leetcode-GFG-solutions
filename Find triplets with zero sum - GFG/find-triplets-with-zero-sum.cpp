//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        sort(arr, arr + n);
        for(int k = 0; k < n; k++) {
            int i = k + 1;
            int j = n - 1;
            while(i < n && j >= k) {
                if(arr[k] + arr[i] + arr[j] == 0 && i != j && j != k && k != i) {
                    return 1;
                } else if(arr[k] + arr[i] + arr[j] < 0) {
                    i++;
                } else {
                    j--;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends