class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int m = strs[0].size(), n = strs.size(), cnt = 0;
        
        for(int i=0;i<m;i++) {
            for(int j=1;j<n;j++) {
                if(strs[j-1][i] > strs[j][i]) {
                    cnt++; break;
                }
            }
        }
        
        return cnt;
        
    }
};