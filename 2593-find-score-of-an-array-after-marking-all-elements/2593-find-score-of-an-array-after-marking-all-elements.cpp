class Solution {
public:
    long long findScore(vector<int>& nums) {
        
        long long score = 0;
        
        // Create a map to store the numbers in ascending order
        // Number will contain their indices in the set
        map<int,set<int>> indices;
        for(int i = 0; i < nums.size(); i++)
            indices[nums[i]].insert(i);
        
        for(auto it: indices) {
            int val = it.first;
            // Mark the indices of the smallest values and their neighbours
            for(auto index: it.second) {
                // Not marked yet
                if(nums[index] != 1e9) {
                    score += nums[index];
                    nums[index] = 1e9;
                    if(index > 0) 
                        nums[index-1] = 1e9;
                    if(index < nums.size()-1) 
                        nums[index+1] = 1e9;
                }
            }
            // Remove the processed value to reduce complexity
            indices[val].clear();
        }
        
        return score;
        
    }
};