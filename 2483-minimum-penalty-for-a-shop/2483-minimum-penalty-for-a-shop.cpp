class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int hours = 0;
        int bestTime = 0;
        int curTime = 0;
        for (int i = 0; i < n; i++) {
            curTime += (customers[i] == 'Y') ? 1 : -1;
            if (bestTime < curTime) {
                bestTime = curTime;
                hours = i + 1;
            }
        }
        return hours;
    }
};