//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        unordered_map<char, int> mp;
        for(auto &it : p) {
            mp[it]++;
        }
        int count = mp.size();
        int i = 0;
        int n = s.size();
        int ans = 1e6;
        int start = -1;
        for(int j = 0; j < n; j++) {
            if(--mp[s[j]] == 0) {
                count--;
            }
            while(count == 0) {
                if(j - i + 1 < ans) {
                    start = i;
                    ans = j - i + 1;
                } 
                if(++mp[s[i]] > 0) {
                    count++;
                }
                i++;
            }
        }
        if(start == -1) return "-1";
        return s.substr(start, ans);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends