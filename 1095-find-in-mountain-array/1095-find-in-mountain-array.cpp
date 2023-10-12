/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int maxIdx = -1, maxVal = -1;
        int low = 1;
        int high = mountainArr.length() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int val1 = mountainArr.get(mid);
            int val2 = mountainArr.get(mid + 1);
            if (val1 > maxVal) maxVal = val1, maxIdx = mid;
            if (val2 > maxVal) maxVal = val2, maxIdx = mid + 1;
            if (val1 < val2) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        low = 0, high = maxIdx;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (mountainArr.get(mid) == target) return mid;
            if (mountainArr.get(mid) < target) low = mid + 1;
            else high = mid - 1;
        }
        low = maxIdx + 1, high = mountainArr.length() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (mountainArr.get(mid) == target) return mid;
            if (mountainArr.get(mid) > target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};