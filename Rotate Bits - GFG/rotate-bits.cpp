//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            string s;
            for (int i = 0; i < 16; i++) {
               int bit = (n >> i) & 1;
               char b = bit + '0';
               s.push_back(b);
            }
            string r(s);
            d %= 16;
            // cout << s << endl;
            int D = d;
            while (D--) {
                r.push_back(r[0]);
                r.erase(r.begin());
            }
            while (d--) {
                s.insert(s.begin(), s.back());
                s.pop_back();
            }
            // cout << s << ' ' << r << endl;
            vector<int> ans;
            int num1 = 0, num2 = 0;
            for (int i = 0; i < 16 ;i++) {
               if (r[i] == '1') {
                  num1 += pow(2, i);
                //   cout << num1 << endl;
               }
            }
            for (int i = 0; i < 16 ;i++) {
               if (s[i] == '1') {
                  num2 += pow(2, i);
               }
            }
            ans.push_back(num2);
            ans.push_back(num1);
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends