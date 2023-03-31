class Solution {
public:
    int numRabbits(vector<int>& answers) {
        
        unordered_map<int,int> rabbits;
        for(auto a : answers)
            rabbits[a]++;
        
        int ans = 0;
        for(auto [x, y] : rabbits) 
            ans += (x+1)*((y+x)/(x+1));
        
        return ans;
    }
};