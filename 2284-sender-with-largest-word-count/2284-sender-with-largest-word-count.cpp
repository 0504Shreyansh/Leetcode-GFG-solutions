class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        
        map<string,int> textCnt;
        for(int i = 0; i < senders.size(); i++) {
            int cnt = 1; 
            for(int j = 0; j < messages[i].size(); j++) 
                cnt += messages[i][j]==' ';
            textCnt[senders[i]] += cnt;
        }
        
        int maxCnt = 0;
        for(auto [x, y] : textCnt)
            maxCnt = max(maxCnt, y);
        
        string ans = "";
        for(auto [x, y] : textCnt) 
            if(maxCnt==y && (ans<x || ans=="")) 
                ans = x;            

        return ans;
    }
};