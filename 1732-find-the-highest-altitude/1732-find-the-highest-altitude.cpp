class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> heights(gain);
        heights.insert(heights.begin(), 0);
        for(int i = 1; i < heights.size(); ++i) {
            heights[i] += heights[i - 1];
        }
        int maxGain = 0;
        for(auto &currGain : heights) {
            maxGain = max(maxGain, currGain);
        }
        return maxGain;
    }
};