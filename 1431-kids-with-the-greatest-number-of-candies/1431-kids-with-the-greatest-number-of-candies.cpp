class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maximumCandies = 0;
        for (int i = 0; i < candies.size(); i++) {
            maximumCandies = max(maximumCandies, candies[i]);
        }
        vector<bool> res;
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= maximumCandies) {
                res.push_back(true);
            }
            else {
                res.push_back(false);
            }
        }
        return res;
    }
};