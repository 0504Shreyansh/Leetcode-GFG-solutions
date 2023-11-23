class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int N = l.size();
        vector<bool> res(N, true);
        for (int i = 0; i < N; ++i) {
            vector<int> temp;
            for (int j = l[i]; j <= r[i]; ++j) 
                temp.push_back(nums[j]);
            sort(begin(temp), end(temp));
            int diff = (temp.back() - temp[0]) / (r[i] - l[i]);
            for (int j = 1; j < temp.size(); ++j) {
                if (temp[j] - temp[j - 1] != diff) {
                    res[i] = false;
                    break;
                }
            }
        }
        return res;
    }
};