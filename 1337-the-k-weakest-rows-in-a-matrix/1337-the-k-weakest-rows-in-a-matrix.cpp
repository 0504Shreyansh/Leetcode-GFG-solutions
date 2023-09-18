class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        vector<pair<int,int>> vp;
        
        for(int i=0;i<mat.size();i++) {
            int cnt = count(mat[i].begin(),mat[i].end(),1);
            vp.push_back({cnt,i});
        }
        
        sort(vp.begin(),vp.end());
        vector<int> ans;
        for(int i=0;i<k;i++) 
            ans.push_back(vp[i].second);
        
        return ans;
        
    }
};