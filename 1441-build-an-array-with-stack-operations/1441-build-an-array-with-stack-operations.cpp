class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int i = 0, num = 1, m = target.size();
        while (i < m && num <= n) {
            if (num == target[i]) {
                ans.push_back("Push");
                i++;
            } else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            num++;
        }
        return ans;
    }
};