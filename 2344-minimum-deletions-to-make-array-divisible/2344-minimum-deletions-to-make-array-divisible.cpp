class Solution {
public:
    // int gcd(int a, int b) {
    //     if(a==0) return b;
    //     return gcd(a%b,a);
    // } 
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        
        int n = nums.size(), g = numsDivide.back();
        int ans = 0;
        for(auto i:numsDivide) {
            g = __gcd(g,i);
            cout<<g<<" ";
        }
        
        sort(nums.rbegin(),nums.rend());
        // cout<<g<<endl;
        // for(auto i:nums) cout<<i<<" "; cout<<endl;
        
        while(nums.size()) {
            if(g%nums.back()==0)
                return ans;
            ans++;
            nums.pop_back();
        }
        
        return -1;
        
    }
};