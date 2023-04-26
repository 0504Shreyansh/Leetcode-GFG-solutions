class Solution {
public:
    int addDigits(int num) {
        while(num/10 != 0) {
            int cur = 0;
            while(num != 0) {
                cur += (num % 10);
                num /= 10;
            }
            num = cur;
        }
        return num;
    }
};