class Solution {
private:
    void calSum(int i, int sum, int n1, vector<int>& nums, map<int, int>& mp) {
        if (i >= n1) {
            mp[sum]++;
            return ;
        }
        calSum(i + 1, sum, n1, nums, mp);
        calSum(i + 1, sum + nums[i], n1, nums, mp);
    }

    int ans = INT_MAX;
    void calSum2(int i, int sum, int n, int goal, vector<int>& nums, vector<int>& A) {
        if (i >= n) {
            int reqSum = goal - sum;
            int ub = upper_bound(begin(A),end(A),reqSum) - begin(A);
            if (ub >= 0 && ub < A.size()) {
                ans = min(ans, abs(reqSum - A[ub]));
            } 
            if (ub - 1 >= 0) {
                ans = min(ans, abs(reqSum - A[ub - 1]));
            }
            return ;
        }
        calSum2(i + 1, sum, n, goal, nums, A);
        calSum2(i + 1, sum + nums[i], n, goal, nums, A);
    }
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        map<int, int> mp;
        int n = nums.size();
        int n1 = n / 2;
        int n2 = n - n / 2;
        calSum(0, 0, n1, nums, mp);    
        vector<int> A;
        for (auto &x : mp) 
            A.push_back(x.first);
        calSum2(n1, 0, n, goal, nums, A);
        return ans;
    }
};