class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        
        int n = colsum.size();
        vector<vector<int>> ans(2, vector<int> (n, 0));
        
        // 2 -> put 1 in both columns
        // 0 -> keep 0 and 0
        for(int i = 0; i < n; i++) {
            if(colsum[i]==2) {
                if(upper && lower) {
                    ans[0][i] = ans[1][i] = 1;
                    upper--, lower--;
                }
                else {
                    ans.clear();
                    return ans;
                }
            }
        }
        
        // For 1 -> depends on upper and lower
        // If upper>0 -> put in upper 
        // else if lower>0 -> then put in lower
        // else if both are exhausted, then ans is not possible
        for(int i = 0; i < n; i++) {
            if(colsum[i]==1) {
                if(upper) {
                    ans[0][i] = 1;
                    upper--;
                }
                else if(lower) {
                    ans[1][i] = 1;
                    lower--;
                }
                else {
                    ans.clear();
                    return ans;
                }
            }
        }
    
        if(lower>0 || upper>0)
            ans.clear();
        return ans;
    }
};