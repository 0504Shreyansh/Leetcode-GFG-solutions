//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s) {
        int n = s.size();
        vector<int> mp(26);
        int i = 0;
        int ans = 0;
        for(int j = 0; j < n; j++) {
            mp[s[j] - 'a']++;
            if(mp[s[j] - 'a'] > 1) {
                while(mp[s[j]-'a'] > 1) {
                    mp[s[i] - 'a']--;
                    i++;
                }
            }
            ans = max(ans, j - i + 1);
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
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends