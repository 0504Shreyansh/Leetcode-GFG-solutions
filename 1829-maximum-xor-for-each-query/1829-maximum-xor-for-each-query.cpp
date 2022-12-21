class Solution {
public:
    /*Use prefixXor and try to maximise the ans (x xor something = 2^maximumBit-1)
    for nums -> [0,1,2,2,5,7], maximumBit=3
    prefixXor -> [0,0^1,0^1^2,0^1^2^2,0^1^2^2^5,0^1^2^2^5^7], maxiXor -> 2 ki power 3 -1
    prefixXor -> [0,1,3,1,4,3], maxiXor -> 7
    reverse preXor -> [3,4,1,3,1,0]
    1. 3^?=7 -> ?=7^3 -> ?=4
    2. 4^?=7 -> ?=7^4 -> ?=3
    3. 1^?=7 -> ?=7^1 -> ?=6
    4. 3^?=7 -> ?=7^3 -> ?=4
    5. 1^?=7 -> ?=7^1 -> ?=6
    6. 0^?=7 -> ?=7^0 -> ?=7
    ans -> [4,3,6,4,6,7]
    */
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        
        vector<int> preXor, ans;
        int x = 0, n = nums.size();
        int maxiXor = (1<<maximumBit) - 1;
        
        for(auto i:nums) {
            x^=i;
            preXor.push_back(x);
        }
        // for(auto i:preXor) cout<<i<<" "; cout<<endl;
        for(int i=n-1;i>=0;i--) {
            int val = maxiXor^preXor[i];
            ans.push_back(val);
        }
            
        return ans;
        
    }
};