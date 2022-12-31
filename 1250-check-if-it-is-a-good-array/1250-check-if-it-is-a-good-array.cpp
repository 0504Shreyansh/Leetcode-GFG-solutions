class Solution {
public:
    /*Concept -> In general, by Bezout formula -
    ax1 + bx2 + ... = d, then -
    gcd(x1,x2...) = d
    Therefore, take the gcd of the array and if it is equal to 1(as given in the question), then it works.
    */
    bool isGoodArray(vector<int>& nums) {
        int gcd = nums.back();
        for(auto i:nums)
            gcd = __gcd(gcd, i);
        return (gcd==1);
    }
};