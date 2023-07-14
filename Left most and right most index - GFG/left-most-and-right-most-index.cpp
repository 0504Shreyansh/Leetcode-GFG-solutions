//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        int lb = lower_bound(begin(v),end(v),x) - begin(v);
        if(lb >= 0 && lb < v.size() && v[lb] == x) {
            int ub = upper_bound(begin(v),end(v),x) - begin(v);
            ub--;
            if(ub >= 0 && ub < v.size() && v[ub] == x) {
                return {lb, ub};
            }
        }  
        return {-1, -1};
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends