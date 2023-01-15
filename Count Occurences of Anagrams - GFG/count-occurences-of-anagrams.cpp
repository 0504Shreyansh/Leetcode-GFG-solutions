//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    //step 1: create mapping of the pat string and count the number of unbiques
	    map<char,int> mp;
	    for(auto x:pat)
	        mp[x]++;
	    
	    int i = 0, j = 0, n = txt.size();
	    int ans = 0, count = mp.size();
	    //step 2: apply sliding window and reach the desired window. 
	    //While going through the process, decrement the count of chars
	    while(j<n) {
	     
	        if(mp.find(txt[j])!=mp.end()) {
	            mp[txt[j]]--;
	            if(mp[txt[j]]==0)
	                count--;
	        }
	        
	        if(j-i+1<pat.size())
	            j++;
	        
	        else {
	   //step 3: check whether same chars with freq or not, increase ans as per it.
	            if(count==0)
	                ans++;
	   //step 4: while removing the ith index, restore its contribution in the map 
	            if(mp.find(txt[i])!=mp.end()) {
	                mp[txt[i]]++;
	                if(mp[txt[i]]==1)
	                    count++;
	            }
	            i++; j++;
	        }
	    }
	    
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends