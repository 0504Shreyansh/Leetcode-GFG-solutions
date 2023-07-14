class Solution {
private:
    bool isPossible(vector<int>& piles, int h, long long mid) {
        if (mid == 0) return 0;
        long long curr = 0;
        for (auto &it : piles) {
            curr += (it + mid - 1) / mid;
        }
        return (curr <= h);
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 0;
        long long high = 0;
        for (auto &it : piles) {
            high += it;
        }
        long long ans = 10000000000;
        while(low <= high) {
            long long mid = (low + high) / 2;
            if(isPossible(piles, h, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } 
        return ans;
    }
};