class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans = 0;
        
        for(int i=0;i<strs.size();i++) {
            int cnt = 0, c=0, s=strs[i].size();
            for(int j=0;j<s;j++) {
                if(strs[i][j]>='a' && strs[i][j]<='z') {
                    c=1; break;
                }
            }
            if(c==1) ans=max(ans,s);
            else ans=max(ans, stoi(strs[i]));
        }
        return ans;
    }
};
