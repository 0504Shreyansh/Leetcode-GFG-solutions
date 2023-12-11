class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size(), num = -1;
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            while (j < n && arr[i] == arr[j]) ++j;
            if (j - i > n / 4) num = arr[i];
            i = j - 1;
        }
        return num;
    }
};