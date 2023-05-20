//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int n, int groupSize, vector<int>& nums) {
        sort(begin(nums),end(nums));
        unordered_map<int,int> mp;
        for(auto it : nums)
            mp[it]++;
        for(int i = 0; i < n; i++) {
            int g = groupSize;
            int num = nums[i];
            while(g > 0 && mp.find(num) != mp.end()) {
                g--;
                if(--mp[num]==0) mp.erase(num);
                num++;
            }
            if(g != groupSize) {
                if(g != 0) {
                    return false;
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends