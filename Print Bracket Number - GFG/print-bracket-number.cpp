//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

	vector<int> bracketNumbers(string S)
	{
	    vector<int> ans;
	    stack<pair<char,int>> st;
	    int prev = 1;
	    int bracNum = 1;
	    for(auto it : S) {
	        if(it == '(') {
	            st.push({'(', prev});
	            ans.push_back(prev);
	            prev++;
	        }
	        else if(it == ')') {
	            ans.push_back(st.top().second);
	            st.pop();
	        } 
	        bracNum += (it == '(');
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	string tc;
   	getline(cin, tc);
   	t = stoi(tc);
   	while(t--)
   	{
   		string s;
   		getline(cin, s);

   	    Solution ob;

   		vector<int> ans = ob.bracketNumbers(s);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends