class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;
        vector<vector<int>> freq(words.size(), vector<int> (26));
        for(int i = 0; i < words.size(); i++) 
            for(int j = 0; j < words[i].size(); j++)
                freq[i][words[i][j]-'a']++;

        for(int i = 0; i < words.size()-1; i++) {
            for(int j = i+1; j < words.size(); j++) {
                vector<int> f = freq[i], ff = freq[j];
                bool fff = 1;
                for(int k = 0; k < 26; k++) {
                    if(f[k] && ff[k]) {
                        fff = 0;
                        break;
                    }
                }
                if(fff)
                    if(ans < words[i].size()*words[j].size())
                        ans = words[i].size()*words[j].size();
            }
        }

        return ans;
    }
};