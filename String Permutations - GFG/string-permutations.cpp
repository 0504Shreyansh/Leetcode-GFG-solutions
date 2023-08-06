//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void f(int i, vector<string>& ans, string &S) {
        if (i >= S.size()) {
            ans.push_back(S);
            return ;
        }
        for (int j = i; j < S.size(); j++) {
            swap(S[i], S[j]);
            f(i + 1, ans, S);
            swap(S[i], S[j]);
        }
    }
    vector<string> permutation(string S)
    {
        vector<string> ans;
        f(0, ans, S);
        sort(begin(ans),end(ans));
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends