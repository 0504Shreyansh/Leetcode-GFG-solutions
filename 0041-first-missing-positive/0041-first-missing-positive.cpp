class Solution
{
    public:
        int firstMissingPositive(vector<int> &nums)
        {

            map<int, int> mp;
            for (auto i: nums)
            {
                if (i > 0) mp[i]++;
            }
            int cnt = 1;
            for (auto i: mp)
            {
                if (cnt != i.first) return cnt;
                else cnt++;
            }
            return cnt;
        }
};