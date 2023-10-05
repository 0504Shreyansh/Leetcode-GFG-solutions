//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  private:
    long long count(string s, int k) {
        long long ans = 0;
        int i = 0;
        vector<int> m(26);
        int c = 0;
        for (int j = 0; j < s.size(); j++) {
            if (++m[s[j] - 'a'] == 1) c++; 
            while (c > k) {
                if (--m[s[i] - 'a'] == 0)
                    c--;
                i++;
            }
            ans += (j - i + 1);
        }
        return ans;
    }
  public:
    long long int substrCount (string s, int k) {
        return count(s, k) - count(s, k - 1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends