class Solution {
public:
    int similarPairs(vector<string>& words) {
        vector<vector<char>> ans;
        int cnt = 0;
        for(auto i:words) {
            set<char> s;
            for(auto j:i) {
                s.insert(j);
            }
            vector<char> t;
            for(auto k:s) {
                t.push_back(k);
            }
            sort(t.begin(),t.end());
            ans.push_back(t);
        }
        for(int i=0;i<ans.size();i++) {
            for(int j=i+1;j<ans.size();j++) {
                if(ans[i]==ans[j]) {
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};
