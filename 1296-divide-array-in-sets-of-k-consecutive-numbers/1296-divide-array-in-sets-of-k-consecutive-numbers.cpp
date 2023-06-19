class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto &it : nums) {
            m[it]++;
        }
        sort(begin(nums),end(nums));
        for(int i = 0; i < nums.size(); i++) {
            int K = k;
            int num = nums[i];
            while(K && m.find(num) != m.end()) {
                if(--m[num] == 0) m.erase(num);
                num++;
                K--;
            }
            if(K != k) {
                if(K != 0) {
                    return false;
                }
            }
        }
        return true;
    }
};