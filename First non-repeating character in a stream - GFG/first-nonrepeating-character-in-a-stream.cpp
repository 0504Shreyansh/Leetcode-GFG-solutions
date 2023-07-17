//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    vector<int> freq(26, 0);
		    string res;
		    queue<char> q;
		    for (int i = 0; i < A.size(); i++) {
		        if (++freq[A[i] - 'a'] == 1) q.push(A[i]);
		        while (q.size() && freq[q.front() - 'a'] > 1) q.pop();
		        res += (q.size()) ? q.front() : '#';
		    }
		    return res;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends