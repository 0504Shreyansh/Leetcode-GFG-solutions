class Solution {
public:
    int kthGrammar(int n, int k) {
        int low = 1, high = pow(2, n - 1);
        string s = "01";
        while (low < high) {
            int mid = (low + high) / 2;
            if (k <= mid) {
                high = mid;
                if (s[0] == '0') {
                    s = "01";
                } else {
                    s = "10";
                }   
            } else {
                low = mid + 1;
                if (s[1] == '0') {
                    s = "01";
                } else {
                    s = "10";
                } 
            }
        }
        return (s[0] - '0');
    }
};