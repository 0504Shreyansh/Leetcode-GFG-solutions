//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s)
{
    map<char,int> mp;
    for(auto i:s) {
        mp[i]++;
        if(mp[i]>1) {
            string ans;
            ans += i;
            return ans;
        }
    }
    return "-1";
}