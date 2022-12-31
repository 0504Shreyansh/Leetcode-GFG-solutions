class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        
        int m = words.size(), n = queries.size();
        vector<int> ans;
        for(int i=0;i<n;i++) {
            int ch = 'z', size = queries[i].size();
            int c = 0;
            for(int k=0;k<queries[i].size();k++) {
                if(queries[i][k]<ch)
                    ch = queries[i][k];
            }
            int cnt = count(queries[i].begin(),queries[i].end(),ch);
            for(int j=0;j<m;j++) {
                int chh = 'z';
                for(int k=0;k<words[j].size();k++) {
                    if(words[j][k]<chh)
                        chh = words[j][k];
                }
                int cntt = count(words[j].begin(),words[j].end(),chh);
                if(cnt<cntt) c++;
                // cout<<cnt<<' '<<cntt<<' '<<c<<endl; 
            }
            ans.push_back(c);
        }
        
        return ans;
    }
};