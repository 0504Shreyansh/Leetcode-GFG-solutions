//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int XOR = 0;
        for (auto &it : nums) {
            XOR ^= it;
        }
        int bit_pos = 0;
        for (int i = 0; i < 25; i++) {
            if (XOR & (1 << i)) {
                bit_pos = i;
                break;
            }
        }
        int x1 = 0, x2 = 0;
        for (auto &it : nums) {
            if (it & (1 << bit_pos)) {
                x1 ^= it;
            } else {
                x2 ^= it;
            }
        }
        return {min(x1, x2), max(x1, x2)};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends