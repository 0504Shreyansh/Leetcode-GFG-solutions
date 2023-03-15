class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        
        map<int,int> powerOf2;
        for(auto x : nums)
            if((x & (x - 1)) == 0)
                powerOf2[x]++;
        
        int num = 1;
        for(auto x : powerOf2) {
            if(!powerOf2[num])
                return num;
            num <<= 1;
        }
    
        return num;
      
    }
};