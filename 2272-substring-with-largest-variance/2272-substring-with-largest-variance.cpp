class Solution {
private:
    int kadane(char c1, char c2, string &s) {
        int n = s.size();
        int maxDiff = 0;
        for(int k = 1; k <= 2; k++) {
            int cmax = 0, cmin = 0;
            for(int i = 0; i < n; i++) {
                if(s[i] == c1) cmax++;
                else if(s[i] == c2) cmin++;
                if(cmax && cmin) maxDiff = max(maxDiff, cmax-cmin);
                if(cmax < cmin) cmax = cmin = 0;
                if(cmax < 0) cmax = 0;
                if(cmin < 0) cmin = 0;
            }
            reverse(begin(s),end(s));
        }
        return maxDiff;
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