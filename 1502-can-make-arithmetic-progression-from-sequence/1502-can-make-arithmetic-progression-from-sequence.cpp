class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        sort(begin(arr),end(arr));
        int diff = (arr.back() - arr[0]) / (n - 1);
        for(int i = 1; i < n; i++) {
            if(arr[i] - arr[i - 1] != diff)
                return false;
        }
        return true;
    }
};