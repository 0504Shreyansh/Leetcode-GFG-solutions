#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ordered_set<int> OS;
        vector<int> ans(n);
        for(int i = n - 1; i >= 0; --i) {
            auto it = OS.order_of_key(nums[i]);
            ans[i] = it;
            OS.insert(nums[i]);
        } 
        return ans;
    }
};