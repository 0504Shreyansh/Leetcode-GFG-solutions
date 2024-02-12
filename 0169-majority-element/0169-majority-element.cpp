class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, ele = -1;
        for (auto &x : nums) {
            if (count == 0) {
                ele = x;
            }
            if (ele == x) {
                count++;
            } else {
                count--;
            }
        }
        return ele;
    }
};