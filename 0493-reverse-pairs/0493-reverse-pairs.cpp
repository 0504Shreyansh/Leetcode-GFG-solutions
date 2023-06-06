#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = 
tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        ordered_set<double> OS;
        int ans = 0;
        for(int i = n - 1; i >= 0; --i) {
            // int find = (nums[i] & 1) + (nums[i]) / 2;
            auto it = OS.order_of_key(nums[i] / 2.0);
            ans += it;
            OS.insert(nums[i]);
        } 
        return ans;
    }
};