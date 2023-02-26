class Solution {
public:
    void chalteJaao(int &curCnt, vector<int> &nums, vector<int> &visited, int index) {
        visited[index] = 1;
        curCnt++;
        if(!visited[nums[index]])
            chalteJaao(curCnt, nums, visited, nums[index]);
        else 
            return ;
    }
    int arrayNesting(vector<int>& nums) {
        
        vector<int> visited(nums.size());
        int maxLength = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(!visited[i]) {
                int curCnt = 0;
                chalteJaao(curCnt, nums, visited, i);
                maxLength = max(maxLength, curCnt);
            }
        }
        return maxLength;
    }
};