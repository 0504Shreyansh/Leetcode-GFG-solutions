class Solution {
/*1. Create a deque and push greater values into it and if the values present at the back of it are smaller than it, then keep popping it. 
  2. The required answer will be the front of the deque.
  3. Process is similar to the sliding window.
  4. Before sliding the window, check whether the front of the dq is equal to the ele being removed, if so the pop the front.
*/
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        vector<int> ans;
        deque<int> dq;
        for (int j = 0; j < n; j++) {
            while (dq.size() && nums[dq.back()] < nums[j]) {
                dq.pop_back();
            }
            dq.push_back(j);
            if (j - i + 1 == k) {
                ans.push_back(nums[dq.front()]);
                if (dq.front() == i) {
                    dq.pop_front();
                }
                i++;
            }
        }
        return ans;
    }
};