class Solution {
public:
    string convert(string s, int numRows) {
        
        vector<string> temp(numRows);
        int i = 0, j = 0;
        while(i<s.size()) {
            for(int j=0;j<numRows;j++) {
                if(i<s.size()) temp[j]+=s[i], i++;
            }
            for(int j=numRows-2;j>0;j--) {
                if(i<s.size()) temp[j]+=s[i], i++;
            }
        }
        
        string ans;
        for(auto i:temp)
            cout<<i<<' ', ans += i;
        
        return ans;
    }
};