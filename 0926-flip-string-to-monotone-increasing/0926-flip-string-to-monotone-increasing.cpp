class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
        int ans = 0, c = 0;
        for(auto i:s) {
            if(i=='1')
                c++;
            else 
                ans++;
            ans = min(ans, c);
        }
        return ans;
        
    }
};