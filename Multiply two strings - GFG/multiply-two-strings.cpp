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
        if (p.size() > s.size()) swap(s, p);
        int n = s.size(), m = p.size();
        vector<int> A(n + m, 0);
        for (int j = m - 1; j >= 0; j--) {
            int carry = 0;
            for (int i = n - 1; i >= 0; i--) {
                A[i + j + 1] += (s[i] - '0') * (p[j] - '0') + carry;
                carry = A[i + j + 1] / 10;
                A[i + j + 1] %= 10;
            }
            if (carry != 0) {
                A[j] += carry;
            }
        }
        string res;
        if (neg1 != neg2) {
            res += '-';
        }
        while (A.size() && A[0] == 0) {
            A.erase(A.begin());
        }
        for (auto &it : A) {
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