//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        string res;
        while (n) {
            int val = (n % 26);
            if (val == 0) val = 26;
            res += (val + 'A' - 1);
            n = (n - 1) / 26;
        }
        reverse(begin(res), end(res));
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends