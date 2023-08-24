//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s, string p) {
        bool neg1 = 0, neg2 = 0;
        if (s[0] == '-') neg1 = 1, s.erase(s.begin());
        if (p[0] == '-') neg2 = 1, p.erase(p.begin());
        while (s.size() && s[0] == '0') s.erase(s.begin());
        while (p.size() && p[0] == '0') p.erase(p.begin());
        if (p.size() > s.size()) swap(s, p);
        int n = s.size(), m = p.size();
        // cout <<s << ' ' << p << endl;
        vector<int> ans(n + m, 0);
        for (int j = m - 1; j >= 0; j--) {
            int carry = 0;
            for (int i = n - 1; i >= 0; i--) {
                ans[i + j + 1] += (p[j] - '0') * (s[i] - '0') + carry;
                carry = ans[i + 1 + j] / 10;
                ans[i + j + 1] %= 10;
            }
            if (carry) {
                ans[j] += carry;
            } 
        }
        string res;
        while (ans.size() && ans[0] == 0) {
            ans.erase(ans.begin());
        }
        if (neg1 != neg2) res += '-';
        for (auto &it : ans) {
            res += it + '0';
        }
        return res;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends