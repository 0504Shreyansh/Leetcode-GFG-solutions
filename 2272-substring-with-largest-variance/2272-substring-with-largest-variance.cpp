class Solution {
private:
    int kadane(char c1, char c2, string &s) {
        int n = s.size();
        int maxSum = 0;
        for(int k = 1; k <= 2; k++) {
            int currSum = 0;
            bool minusOneTaken = false;
            for(int i = 0; i < n; i++) {
                if(s[i] == c1) {
                    currSum += 1;
                } else if(s[i] == c2) {
                    currSum -= 1;
                    minusOneTaken = true;
                }
                if(currSum < 0) currSum = 0, minusOneTaken = false;
                if(minusOneTaken) maxSum = max(maxSum, currSum);
            }
            reverse(begin(s),end(s));
        }
        return maxSum;
    }

public:
    int largestVariance(string s) {
        set<char> st(begin(s),end(s));
        vector<char> temp;
        for(auto &it : st) temp.push_back(it);
        int m = temp.size();
        // pick up 2 diff chars to act as maxOcc and minOcc
        // apply kadane's to find out max diff (include both the chars)
        int maxVariance = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                if(i == j) continue;
                int currVariance = kadane(temp[i], temp[j], s);
                maxVariance = max(maxVariance, currVariance);
            }
        }
        return maxVariance;
    }
};